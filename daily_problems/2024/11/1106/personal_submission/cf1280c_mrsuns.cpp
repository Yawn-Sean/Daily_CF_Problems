void Solve() {
    int n;cin >> n;n *= 2;
    vector<vector<array<int, 2>>> g(n + 1);
    for (int i = 1;i < n;i++) {
        int u, v, w;cin >> u >> v >> w;
        g[u].push_back({ v,w });
        g[v].push_back({ u,w });
    }
    vector<int> sz(n + 1);
    int res_1 = 0, res_2 = 0;
    auto dfs = [&](auto&& dfs, int u, int p)->void {
        sz[u] = 1;
        for (auto [v, w] : g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
            sz[u] += sz[v];
            res_1 += min(sz[v], n - sz[v]) * w;
            res_2 += (sz[v] % 2) * w;
        }
        };
    dfs(dfs, 1, 1);
    cout << res_2 << " " << res_1 << endl;
}
