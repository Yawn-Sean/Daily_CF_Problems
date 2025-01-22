void solve() {
    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    vi p(n);
    vl dp(n+1);
    in(p);
    for (int i = 0; i < n; ++i) {
        dp[i+1] = (2 * dp[i] - dp[p[i] - 1] + 2 + mod) % mod;
    }
    cout << dp[n] << nl;
}
