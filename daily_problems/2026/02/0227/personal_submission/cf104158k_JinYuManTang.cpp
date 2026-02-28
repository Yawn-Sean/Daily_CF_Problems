void solve() {
    int n, m;
    cin >> n >> m;
    HLD hld(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        hld.addEdge(u, v);
    }
    hld.work();
    vector<int> cnt(n);
    i64 res = 0;

    vector<pair<int, int>> paths;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        paths.push_back({s, e});
        int lca = hld.lca(s, e);
        cnt[lca]++;
        res -= cnt[lca];
    }

    auto dfs = [&](auto &dfs, int u, int fa) -> void {
        for (int v: hld.adj[u]) {
            if (v == fa) continue;
            cnt[v] += cnt[u];
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 0, -1);
    for (auto [s, e] : paths) {
        int lca = hld.lca(s, e);
        if (lca) {
            res -= cnt[hld.parent[lca]];
        }
        res += cnt[s] + cnt[e] - cnt[lca];
    }
    cout << res << '\n';
}
