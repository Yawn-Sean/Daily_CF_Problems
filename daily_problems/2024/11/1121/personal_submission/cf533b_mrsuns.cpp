void Solve() {
    int n;cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        int p;cin >> p >> a[i];
        if (p != -1) g[p].push_back(i);
    }
    int res = 0;
    vector<vector<int>> dp(n + 1, vector<int>(2));
    auto dfs = [&](auto&& dfs, int u, int p)->void {
        vector<int> aux(2);aux[1] = -1e18;
        for (auto v : g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
            auto naux = aux;
            naux[0] = max(dp[v][0] + aux[0], dp[v][1] + aux[1]);
            naux[1] = max(dp[v][1] + aux[0], dp[v][0] + aux[1]);
            swap(aux, naux);
        }
        dp[u][1] = max(aux[0] + a[u], aux[1]);
        dp[u][0] = aux[0];
        res = max(res, dp[u][0]);
        res = max(res, dp[u][1]);
        };
    dfs(dfs, 1, 1);
    cout << res << endl;
}
