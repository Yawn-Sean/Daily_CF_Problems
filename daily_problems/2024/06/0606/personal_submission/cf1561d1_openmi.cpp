void solve() {
    ll n, mod;
    cin >> n >> mod;
    vl dp(n + 1);
    dp[1] = 1;
    ll sum = 0;
    rb (i, 1, n) {
        dp[i] += sum; dp[i] %= mod;
        for (int l = 2, r; l <= i; l = r + 1) {
            r = i / (i / l);
            dp[i] += (r - l + 1) * dp[i/l] % mod;
            dp[i] %= mod;
        }
        sum += dp[i]; sum %= mod;        
    }
    cout << dp[n] << nl;
}
