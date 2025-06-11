void Solve() {
    int n, k;cin >> n >> k;
    vector<int> a(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= 2 * k;i++) {
        int x;cin >> x;a[x] = 1;
    }
    for (int i = 1;i < n;i++) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> sz(n + 1);
    int res = 0;
    auto dfs = [&](auto&& dfs, int u, int p)->void {
        sz[u] = a[u];
        for (auto v : g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
            sz[u] += sz[v];
            res += min(sz[v], 2 * k - sz[v]);
        }
        };
    dfs(dfs, 1, 1);
    cout << res << endl;
}
 
