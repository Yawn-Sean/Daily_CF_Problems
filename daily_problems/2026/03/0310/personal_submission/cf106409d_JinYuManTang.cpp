void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int u = 0; u < n; u++) {
        for (int v: g[u]) {
            for (int i = 0; i < min(3, (int)g[u].size()); i++) {
                for (int j = 0; j < min(3, (int)g[v].size()); j++) {
                    int x = g[u][i], y = g[v][j];
                    if (x != v && y != u && x != y) {
                        cout << x + 1 << '\n' << u + 1 << '\n' << v + 1 << '\n' << y + 1 << '\n';
                        return;
                    }
                }
            }
        }
    }
    cout << -1;
}
