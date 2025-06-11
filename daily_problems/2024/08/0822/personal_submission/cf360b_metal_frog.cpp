void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll lo = 0, hi = 2e9;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        vector<int> dp(n, 1);
        int maxRem = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < i; j++) {
                if (abs(a[i] - a[j]) <= mid * (i - j)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxRem = max(dp[i], maxRem);
        }
        if (maxRem >= n - k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
}
