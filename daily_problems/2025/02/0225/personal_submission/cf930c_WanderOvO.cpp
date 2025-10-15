/*
min_val[i]: 长度为 i 的最长不降子序列的最后一个数字的最小值
*/

int dp[3][N], n, m, a[N], min_val[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    for (int i = 1; i <= m; i++) {
        a[i] += a[i - 1];
    }

    min_val[1] = a[1];
    dp[1][1] = 1;
    int idx = 1;
    for (int i = 2; i <= m; i++) {
        int pos = upper_bound(min_val + 1, min_val + idx + 1, a[i]) - min_val;
        if (pos == idx + 1) {
            idx++;
        } 
        min_val[pos] = a[i];
        dp[1][i] = pos;
    }

    memset(min_val, 0, sizeof min_val);
    dp[2][m] = 1;
    min_val[1] = a[m];
    idx = 1;
    reverse(a + 1, a + m + 1);
    for (int i = 2; i <= m; i++) {
        int pos = upper_bound(min_val + 1, min_val + idx + 1, a[i]) - min_val;
        if (pos == idx + 1) {
            idx++;
        }
        min_val[pos] = a[i];
        dp[2][m - i + 1] = pos;
    }
    for (int i = 2; i <= m; i++) {
        dp[1][i] = max(dp[1][i], dp[1][i - 1]);
    }
    for (int i = m - 1; i > 0; i--) {
        dp[2][i] = max(dp[2][i], dp[2][i + 1]);
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
        res = max(res, dp[1][i] + dp[2][i + 1]);
    }
    cout << res << "\n";
}   
