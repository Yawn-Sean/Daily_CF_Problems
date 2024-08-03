void solve1() {
    int n, k;
    cin >> n >> k;
    vector<vector<LL>> c(n + 1, vector<LL>(n + 1, 0));
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= min(i, k); j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    vector<LL> d = {0, 0, 1, 2, 9};
    LL res = 1;
    for (int i = 2; i <= k; i++) {
        res += c[n][i] * d[i];
    }
    cout << res << '\n';
}    
