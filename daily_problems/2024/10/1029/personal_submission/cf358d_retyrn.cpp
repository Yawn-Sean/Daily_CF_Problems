int n;

void solve() {
    cin >> n;
    vector<int> a(n), b(n), c(n);
    cin >> a >> b >> c;
    
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    
    // 0表示后两项第一项先到 1表示后两项第二项先到
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[1][0] = a[0];
    dp[1][1] = b[0];
    
    for (int i = 2; i < n; i ++) {
        // 0
        dp[i][0] = max(dp[i-1][0] + b[i-1], dp[i-1][1] + a[i-1]);
        dp[i][1] = max(dp[i-1][0] + c[i-1], dp[i-1][1] + b[i-1]);
    }
    int res = max(dp[n-1][0] + b[n-1], dp[n-1][1] + a[n-1]);
    cout << res << endl;
}