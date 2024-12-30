int x, k, p;

void solve() {
    cin >> x >> k >> p;
    double p1 = p / 100.0;
    double p2 = 1.0 - p1;
    
    vector<vector<double>> dp(k + 1, vector<double>(k + 1));
    // dp[i][j] 第i次操作时 欠了j次+1的期望0的个数
    
    for (int i = 0; i <= k; i ++) {
        auto t = x + i;
        t = t & -t;
        dp[0][i] = std::__lg(t);
    }
    
    for (int i = 0; i < k; i ++) {
        for (int j = 0; j <= k; j ++) {
            if (j * 2 <= k) dp[i+1][j*2] += (dp[i][j] + 1) * p1;
            if (j > 0) dp[i+1][j-1] += dp[i][j] * p2;
        }
    }
    
    cout << dp[k][0] << endl;
    
}