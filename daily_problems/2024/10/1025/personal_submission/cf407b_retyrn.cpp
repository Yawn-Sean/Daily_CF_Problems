int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] -= 1;
    }
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i ++) {
        dp[i + 1] = (dp[i] * 2 % mod - dp[a[i]] + 2 + mod) % mod;
    }
    cout << dp[n] << endl;
}