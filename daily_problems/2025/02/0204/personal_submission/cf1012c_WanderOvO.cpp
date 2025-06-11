/*
注意是**至少**有 k 个数满足比相邻的数大
最开始可能就有一些数满足比相邻的数大
相邻的数一定不能都满足比相邻的数大
dp[i][j][0/1]: 前 i 个数，有 j 个满足比相邻数大，第 i 个数不满足/满足条件的最小操作次数
dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + max(0, a[i - 1] - a[i] + 1))
dp[i][j][1] = dp[i - 2][j - 1][0] + max(0, a[i] - a[i - 1] + 1)
dp[i][j][1] = dp[i - 2][j - 1][1] + more_cost
a[i - 1] 目前是 min(a[i - 1], a[i - 2] - 1)
more_cost = 
- min(a[i - 1], a[i - 2] - 1), if min(a[i - 1], a[i - 2] - 1) < a[i]
- a[i - 1] - a[i] + 1, if min(a[i - 1], a[i - 2] - 1) >= a[i]
*/

LL dp[N][N][2];
LL a[N], n;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    dp[1][1][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= (i + 1) / 2; j++) {
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + max(0LL, a[i] - a[i - 1] + 1));
            if (j >= 1) {
                dp[i][j][1] = dp[i - 2][j - 1][0] + max(0LL, a[i - 1] - a[i] + 1);
                LL cur_last = min(a[i - 1], a[i - 2] - 1);
                LL more_cost;
                if (cur_last < a[i]) {
                    more_cost = a[i - 1] - cur_last;
                } else {
                    more_cost = a[i - 1] - a[i] + 1;
                }
                dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][1] + more_cost);
            } else {

            }
        }
    }
    for (int i = 1; i <= (n + 1) / 2; i++) {
        cout << min(dp[n][i][0], dp[n][i][1]) << " ";
    }
}
