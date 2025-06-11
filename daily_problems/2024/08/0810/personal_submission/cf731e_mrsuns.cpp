void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vector<int> s(n + 1);for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
    vector dp(2, vector<int>(n + 1));
    vector<int> dp2(2);
    dp[0][n] = dp[1][n] = 0;
    dp2[0] = -s[n]; dp2[1] = s[n];
    for (int i = n - 1;i >= 2;i--) {
        dp[0][i] = dp2[1];
        dp[1][i] = dp2[0];
        cmin(dp2[0], dp[0][i] - s[i]);
        cmax(dp2[1], dp[1][i] + s[i]);
    }
    int res = dp2[1];
    cout << res << endl;
}
