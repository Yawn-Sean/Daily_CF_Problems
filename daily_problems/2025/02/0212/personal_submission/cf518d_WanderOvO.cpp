/*
枚举到底上去了几个人
假设上去了 cnt 个人，则相当于 C(t, cnt) * p^cnt * (1 - p)^(t - cnt)
当 cnt < n 时，上面这样求就好了
cnt = n 时，需要枚举最后一次上人是第几分钟，假设是第 i 分钟，就是 C(i - 1, cnt - 1) * p^cnt * (1 - p)^(i - cnt)
但是 C(t, cnt) 爆精度了，不能这么做
考虑 dp 做法
dp[i][j] 为第 i 分钟时电梯上有 j 个人的概率
dp[i][j] = dp[i - 1][j] * (1 - p) + dp[i - 1][j - 1] * p
单独处理 j = n 的情况
*/

int n, t;
double p, dp[M][M];

void meibao() {
    cin >> n >> p >> t;
    dp[0][0] = 1;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= min(i, n - 1); j++) {
            dp[i][j] = dp[i - 1][j] * (1 - p);
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * p;
            }
        }
        if (i >= n) {
            dp[i][n] += dp[i - 1][n];
            dp[i][n] += dp[i - 1][n - 1] * p;
        }
    }
    double res = 0;
    for (int j = 0; j <= min(t, n); j++) {
        res += j * dp[t][j];
    }
    cout << setprecision(15) << res << "\n";
}
