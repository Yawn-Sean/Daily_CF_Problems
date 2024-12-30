/* 
https://codeforces.com/problemset/submission/1051/266400026
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<i64>>> dp(n, vector<vector<i64>>(m + 1, vector<i64>(4)));
    dp[0][1][0] = dp[0][1][3] = 1;
    if (m >= 2)
        dp[0][2][1] = dp[0][2][2] = 1;
    for (int i = 1; i < n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            for (int s = 0; s < 4; s ++ ) {
                dp[i][j][s] = dp[i - 1][j][s];
                if (s == 0 || s == 3) dp[i][j][s] = (dp[i][j][s] + dp[i - 1][j][1] + dp[i - 1][j][2]) % MOD2;
                if (s != 0) dp[i][j][s] = (dp[i][j][s] + dp[i - 1][j - 1][0]) % MOD2;
                if (s != 3) dp[i][j][s] = (dp[i][j][s] + dp[i - 1][j - 1][3]) % MOD2;
                if (s != 0 && s != 3 && j >= 2) dp[i][j][s] = (dp[i][j][s] + dp[i - 1][j - 2][3 - s]) %MOD2;
            }
        }
    }
    i64 fin = 0;
    for (int i = 0; i < 4; i ++ ) {
        fin += dp[n - 1][m][i];
    }
    cout << fin % MOD2 << endl;
}
