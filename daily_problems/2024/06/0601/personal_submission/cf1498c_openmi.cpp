void solve() {
    int n, k;
    cin >> n >> k;
    vvc<int> dp(n + 1, vi(k + 1));
    const int mod = 1000'000'007;
    rb (j, 1, k) {
        dp[0][j] = 1;
        rb (i, 1, n) {
            dp[i][j] = (dp[i - 1][j] + dp[n - i][j - 1]) % mod;
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][k] << nl;
}
