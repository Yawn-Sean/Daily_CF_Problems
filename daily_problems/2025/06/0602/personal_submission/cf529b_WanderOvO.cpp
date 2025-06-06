/*
似乎可以枚举最终的 h 是多大，然后求最小的 sum(w)
假设最终的 h 是 final_h，则所有 > final_h 的必须旋转
对于剩下的，假如旋转完 w <= final_h，则可以旋转
设 dp[i][j] 为前 i 个里面旋转 j 个的最小 w 之和
dp[i][j] = min(dp[i - 1][j] + w[i] if h[i] <= findl_h, dp[i - 1][j - 1] + h[i] if w[i] <= final_h)
计算量是 5e8，2s，可以冲
*/

int n, w[M], h[M], dp[M][M / 2];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> h[i];
    }

    int res = 1e9 + 10;

    auto calc = [&] (int final_h) -> int {
        memset(dp, 0x3f, sizeof dp);
        int res = 1e9 + 10;
        int half = n / 2;
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(half, i); j++) {
                if (h[i] <= final_h) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + w[i]);
                } 
                if (j > 0) {
                    if (w[i] <= final_h) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + h[i]);
                    } 
                }
            }
        }
        for (int j = 0; j <= half; j++) {
            res = min(res, dp[n][j]);
        }
        int max_sum = 1e6 + 10;
        int inf = 1e9 + 10;
        if (res >= max_sum) {
            return inf;
        }
        return res * final_h;
    };

    for (int final_h = 1; final_h <= 1000; final_h++) {
        res = min(res, calc(final_h));
    }

    cout << res << "\n";
}
