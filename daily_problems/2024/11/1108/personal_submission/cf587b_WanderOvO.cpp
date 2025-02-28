LL n, l, k, a[N];
PII b[N];

void meibao() {
    cin >> n >> l >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i].x = a[i];
        b[i].y = i;
    }
    int mod = MOD1;
    sort(b + 1, b + n + 1);
    vector<LL> dp(N, 0);
    LL res = 0;
    for (int rd = 1; rd <= k; rd++) {
        int pos = 0;
        LL cur_sum = 0;
        for (int i = 1; i <= n; i++) {
            int p = (rd - 1) * n + b[i].y;
            if (rd == 1) {
                dp[p] = 1;
            } else {
                while (pos + 1 <= n && b[i].x >= b[pos + 1].x) {
                    pos++;
                    cur_sum += dp[(rd - 2) * n + b[pos].y];
                    cur_sum %= mod;
                }
                dp[p] = cur_sum;
            }
            // cnt * n + p <= l
            // cnt <= (l - p) / n
            if (l >= p) {
                LL cnt = (l - p) / n + 1;
                if (cnt > 0) {
                    res += (cnt % mod) * dp[p] % mod;
                    res %= mod;
                }
            }
        }
    }
    cout << res << "\n";
}
