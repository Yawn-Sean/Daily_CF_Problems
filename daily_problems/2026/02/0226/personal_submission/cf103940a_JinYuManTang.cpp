void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[v].emplace_back(u, w);
    }

    vector<int> cost(n, c + 1);
    cost[0] = 1;
    for (int i = 0; i < c; i++) {
        for (int u = 1; u < n; u++) {
            int sum = 0;
            for (auto [v, w]: g[u]) {
                sum += cost[v] + w;
            }
            chmin(cost[u], sum);
        }
    }
    vector<Z> f(c + 1);
    f[0] = 1;
    for (auto x: cost) {
        for (int j = x; j <= c; j++) {
            f[j] += f[j - x];
        }
    }
    Z res = 0;
    for (int j = 1; j <= c; j++) {
        res += f[j];
    }
    cout << res.val();
}
