int h, n, p[N], dp[N];

void meibao() {
    cin >> h >> n;
    for (int i = n; i > 0; i--) {
        cin >> p[i];
    }
    
    for (int i = 2; i <= n; i++) {
        if (p[i - 2] + 1 == p[i - 1]) {
            dp[i] = dp[i - 2];
        } else {
            dp[i] = dp[i - 1] + 1;
        }
    }
    cout << dp[n] << "\n";
}   
