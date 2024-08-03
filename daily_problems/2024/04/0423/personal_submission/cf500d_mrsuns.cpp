void Solve() {
    int n;cin >> n;
    vector<vector<array<int, 3>>> g(n + 1);
    vector<int> W(n);
    vector<int> L(n);
    for (int i = 1;i < n;i++) {
        int u, v, w;cin >> u >> v >> w;
        g[u].push_back({ v,w ,i });
        g[v].push_back({ u,w ,i });
        W[i] = w;
    }
    vector<int> sz(n + 1);
    double res = 0, base = 6. / n / (n - 1);
    auto dfs = [&](auto&& dfs, int u, int p)->void {
        for (auto [v, w, idx] : g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
            sz[u] += sz[v];
        }
        for (auto [v, w, idx] : g[u]) {
            if (v == p) continue;
            int l = sz[v], r = n - sz[v];
            L[idx] = l;
            res += 1. * l * r * base * w;
        }
        sz[u] += 1;
        };
    dfs(dfs, 1, 1);
    int q;cin >> q;
    for (int i = 1;i <= q;i++) {
        int id, w;cin >> id >> w;
        res -= 1. * L[id] * (n - L[id]) * base * W[id];
        W[id] = w;
        res += 1. * L[id] * (n - L[id]) * base * W[id];
        cout << res << endl;
    }

}
