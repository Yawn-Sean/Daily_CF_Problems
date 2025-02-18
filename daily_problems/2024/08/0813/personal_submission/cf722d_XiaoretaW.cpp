const int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, l, r; cin >> t >> l >> r;
    vector<ll> dp(r + 1, 1e18);
    vector<vector<int>> p(r + 1);
    for (int j = 1; j <= r; j++) {
        for (int k = j; k <= r; k += j) {
            setmin(dp[k], 1ll * k * (k - 1) / 2);
            int a = j, b = k / j;
            setmin(dp[k], dp[b] + 1ll * k * (a - 1) / 2);
            setmin(dp[k], dp[a] + 1ll * k * (b - 1) / 2);
        }
    }
  
    ll ans = 0;
    ll base = 1;
    for (int x = l; x <= r; x++) {
        ans = (ans + base * (dp[x] % mod) % mod) % mod;
        base = base * t % mod;
    }

    cout << ans << '\n';
    
    return 0;
}
