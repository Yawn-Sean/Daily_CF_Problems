/*
dp[i][0/1][0/1/2]: 前 i 个字符里的最长的交替串长度
dp[i][0][0] = max(dp[j][1][0]) + 1
dp[i][0][1] = max(dp[j][1][0], dp[j][1][1]) + 1
dp[i][0][2] = max(dp[j][1][0], dp[j][1][1], dp[j][1][2]) + 1
dp[i][1][0] = max(dp[j][0][0]) + 1
dp[i][1][1] = max(dp[j][0][0], dp[j][0][1]) + 1
dp[i][1][2] = max(dp[j][0][0], dp[j][0][1], dp[j][0][2]) + 1
*/

string s;
int n, dp[N][2][3];

void meibao() {
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
            }
        }
        int cur = s[i] - '0';
        int flip_cur = 1 - cur;
        dp[i][cur][0] = max({dp[i][cur][0], dp[i - 1][flip_cur][0] + 1});
        dp[i][flip_cur][1] = max({dp[i][flip_cur][1], dp[i - 1][cur][0] + 1, dp[i - 1][cur][1] + 1});
        dp[i][cur][2] = max({dp[i][cur][2], dp[i - 1][flip_cur][0] + 1, dp[i - 1][flip_cur][1] + 1, dp[i - 1][flip_cur][2] + 1});
    }
    int res = 0;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 3; k++) {
            res = max(res, dp[n][j][k]);
        }
    }
    cout << res << "\n";
}   
