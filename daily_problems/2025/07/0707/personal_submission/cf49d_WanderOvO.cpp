/*
要么是 1010，要么是 0101，按照这两个来涂色
dp[l][r][0] = min(dp[l + 1][r][1] + cost(l), dp[l][r - 1][0] + cost(r))
*/
 
int n, dp[M][M][2];
string s;
 
void meibao() {
    cin >> n >> s;
    s = " " + s;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) {
        dp[i][i][0] = (s[i] == '0' ? 0 : 1);
        dp[i][i][1] = (s[i] == '1' ? 0 : 1);
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            int val1 = dp[i + 1][j][1];
            int val2 = dp[i][j - 1][0];
 
            if (s[i] != '0') {
                val1++;
            }
            if (s[j] != ('0' + (j - i) % 2)) {
                val2++;
            }
            dp[i][j][0] = min(val1, val2);
        
            val1 = dp[i + 1][j][0];
            val2 = dp[i][j - 1][1];
            if (s[i] != '1') {
                val1++;
            }
            if (s[j] != ('0' + (j - i - 1) % 2)) {
                val2++;
            }
            dp[i][j][1] = min(val1, val2);
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]) << "\n";
}
