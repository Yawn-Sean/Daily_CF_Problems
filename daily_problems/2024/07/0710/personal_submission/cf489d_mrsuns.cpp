void Solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i <= m;i++) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
    }
    vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
    for (int i = 1;i <= n;i++) {
        for (auto j : g[i]) {
            for (auto k : g[j]) {
                if (k != i) cnt[i][k] += 1;
            }
        }
    }
    int res = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            res += cnt[i][j] * (cnt[i][j] - 1) / 2;
        }
    }
    cout << res << endl;
}
