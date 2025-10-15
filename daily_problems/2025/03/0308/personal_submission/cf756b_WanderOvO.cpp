LL n, t[N], dp[N];


void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++) {
        LL cur_time = t[i];
        dp[i] = dp[i - 1] + 20;
        int pos = lower_bound(t + 1, t + n + 1, cur_time - 90 + 1) - t;
        if (pos > 0) {
            dp[i] = min(dp[i], dp[pos - 1] + 50);
        } else {
            dp[i] = min(dp[i], 50LL);
        }
        pos = lower_bound(t + 1, t + n + 1, cur_time - 1440 + 1) - t;
        if (pos > 0) {
            dp[i] = min(dp[i], dp[pos - 1] + 120);
        } else {
            dp[i] = min(dp[i], 120LL);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] - dp[i - 1] << "\n";
    }
}   
