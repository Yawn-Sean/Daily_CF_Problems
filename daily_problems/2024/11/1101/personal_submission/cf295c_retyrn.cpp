int n, w;
ll C[55][55];
ll dp[210][55][55];  // dp[i][j][k] 第i轮 右岸有j个轻人 k个重人
bool st[210][55][55];

void solve() {
    cin >> n >> w;
    w /= 50;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if (x == 50) c1 ++;
        else c2 ++;
    }
    
    for (int i = 0; i <= 50; i ++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j ++) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    
    dp[0][0][0] = 1;
    st[0][0][0] = true;
    
    for (int i = 1; i <= n * 4; i ++) {
        for (int j = 0; j <= c1; j ++) {
            for (int k = 0; k <= c2; k ++) {
                if (i & 1) {
                    // 过去
                    for (int a = 0; a <= j; a ++) {
                        for (int b = 0; b <= k; b ++) {
                            if (a + b == 0 or a + b * 2 > w or !st[i-1][j-a][k-b]) continue;
                            dp[i][j][k] = (dp[i][j][k] + C[j][a] * C[k][b] % mod * dp[i-1][j-a][k-b]) % mod;
                            st[i][j][k] = true;
                        }
                    }
                }
                else {
                    // 回来
                    for (int a = 0; a + j <= c1; a ++) {
                        for (int b = 0; b + k <= c2; b ++) {
                            if (a + b == 0 or a + b * 2 > w or !st[i-1][j+a][k+b]) continue;
                            dp[i][j][k] = (dp[i][j][k] + C[c1-j][a] * C[c2-k][b] % mod * dp[i-1][j+a][k+b]) % mod;
                            st[i][j][k] = true;
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i <= n * 4; i ++) {
        if (st[i][c1][c2]) {
            cout << i << endl << dp[i][c1][c2] << endl;
            return;
        }
    }
    
    cout << -1 << endl << 0 << endl;
}