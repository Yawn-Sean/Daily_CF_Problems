/*
前 i 个围栏，涂了总共 j 的红色和 k 的绿色，当前涂的红色/绿色，最小吸引力是多少
dp[i][j][k][0/1]
dp[i][j][k][0] = min(dp[i - 1][j - a[i]][k][0], dp[i - 1][j - a[i]][k][1] + min(a[i], a[i - 1]))
dp[i][j][k][1] = min(dp[i - 1][j][k - a[i]][0] + min(a[i], a[i - 1]), dp[i - 1][j][k - a[i]][1])
事实上，前 i 个总共有 sum 个单位，涂了 i 个红色，自然有 sum - i 个涂了绿色，所以只需要枚举一维
*/

int n, cnt1, cnt2, a[N], dp[N][M][2];

void meibao() {
    cin >> n >> cnt1 >> cnt2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        for (int j = 0; j <= min(cnt1, sum); j++) {
            if (sum - j > cnt2) continue;
            if (j >= a[i]) {
                dp[i][j][0] = min(dp[i - 1][j - a[i]][0], dp[i - 1][j - a[i]][1] + min(a[i], a[i - 1]));
            }
            if (sum - j >= a[i]) {
                dp[i][j][1] = min(dp[i - 1][j][0] + min(a[i], a[i - 1]), dp[i - 1][j][1]);
            }
        }
    }
    int res = INF;
    for (int j = 0; j <= min(cnt1, sum); j++) {
        if (sum - j > cnt2) continue;
        res = min({res, dp[n][j][0], dp[n][j][1]});
    }
    if (res > INF / 2) {
        res = -1;
    }
    cout << res << "\n";
}
