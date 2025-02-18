void Solve() {
    int x, n;ld p;cin >> x >> n >> p;
    p /= 100;
    vector dp(n + 1, vector<ld>(n + 1));
    for (int i = 0;i <= n;i++) dp[0][i] = get(x + i);
    for (int i = 0;i < n;i++) {
        for (int j = 0;j <= n;j++) {
            if (j * 2 <= n) dp[i + 1][j * 2] += (dp[i][j] + 1) * p;
            if (j) dp[i + 1][j - 1] += dp[i][j] * (1 - p);
        }
    }
    cout << dp[n][0] << endl;
}
