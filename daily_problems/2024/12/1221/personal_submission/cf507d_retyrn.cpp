int n, m, mod;
int dp[1010][110][2];
// dp[i][j][k]: 现在在倒数第i位 模m是j 后缀是不是合法

void solve() {
    cin >> n >> m >> mod;
    dp[0][0][0] = 1;
    ll t = 1;
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            // 枚举这一位填什么
            for (int k = 0; k < 10; k ++) {
                if (i == n - 1 and k == 0) continue;
                int cur = (k * t + j) % m;
                dp[i+1][cur][1] += dp[i][j][1];
                if (dp[i+1][cur][1] >= mod) dp[i+1][cur][1] -= mod;
                
                if (!cur and k) {
                    dp[i+1][cur][1] += dp[i][j][0];
                    if (dp[i+1][cur][1] >= mod) dp[i+1][cur][1] -= mod;
                }
                else {
                    dp[i+1][cur][0] += dp[i][j][0];
                    if (dp[i+1][cur][0] >= mod) dp[i+1][cur][0] -= mod;
                }
            }
        }
        t = t * 10 % m;
    }
    
    int res = 0;
    for (int i = 0; i < m; i ++) {
        res = (res + dp[n][i][1]) % mod;
    }
    cout << res << endl;
}