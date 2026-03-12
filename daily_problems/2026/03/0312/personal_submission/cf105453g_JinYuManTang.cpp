void solve() {
    int n, T;
    cin >> n >> T;
    vector<int> t(n), a(n);
    i64 res = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        int b, c;
        cin >> b >> c;
        res += c;
        a[i] = b - c;
    }
    vector<int> dp(n + 1);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (t[i] - t[j] >= T and j < i) {
            j++;
        }
        dp[i + 1] = max(dp[i], dp[j] + a[i]);
    }
    res += dp[n];
    cout << res;
}
