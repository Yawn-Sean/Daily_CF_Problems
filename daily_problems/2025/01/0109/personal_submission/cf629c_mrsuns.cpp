void Solve() {
    int n, m;cin >> n >> m;
    string s;cin >> s;
    vector<vector<int>> dp(2002, vector<int>(2002));
    dp[0][0] = 1;
    for (int i = 1;i <= 2000;i++) {
        for (int j = 0;j <= 2000;j++) {
            dp[i][j] = ((j ? dp[i - 1][j - 1] : 0) + dp[i - 1][j + 1]) % MOD;
        }
    }
    int mn = 0, c = 0;
    for (auto i : s) {
        c += (i == '(' ? 1 : -1);
        mn = min(mn, c);
    }
    int res = 0;
    for (int i = 0;i <= n - m;i++) {
        for (int j = -mn;j + c <= n - m - i and j <= n - m;j++) {
            res = (res + dp[i][j] * dp[n - i - m][j + c] % MOD) % MOD;
        }
    }

    cout << res << endl;
}
