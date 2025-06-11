/*
dp[i][j][0/1/2/3]: 前 i 列，分成 j 个连通块，最后一列的染色方法为 0/1/2/3 的方案数
*/

int T;
LL dp[N][N][4], n, k;

void solve1() {
    cin >> n >> k;
    dp[1][1][0] = 1;
    dp[1][2][1] = 1;
    dp[1][2][2] = 1;
    dp[1][1][3] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] 
                        + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % MOD2;

            dp[i][j][1] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1]
                        + dp[i - 1][j - 1][3]) % MOD2;
            if (j >= 2) {
                dp[i][j][1] += dp[i - 1][j - 2][2];
                dp[i][j][1] %= MOD2;
            }

            dp[i][j][2] = (dp[i - 1][j - 1][0] + dp[i - 1][j][2] 
                        + dp[i - 1][j - 1][3]) % MOD2;
            if (j >= 2) {
                dp[i][j][2] += dp[i - 1][j - 2][1];
                dp[i][j][2] %= MOD2;
            }

            dp[i][j][3] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1]
                        + dp[i - 1][j][2] + dp[i - 1][j][3]) % MOD2;
        }
    } 
    cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % MOD2;
}              