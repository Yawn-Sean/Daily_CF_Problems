/*
dp[i][j][0/1]: 组成长度为 i 的围栏，最后一块木板用的类型是 j，没旋转/旋转的方案数
dp[i][j][0] += dp[i - a[j]][k][0], k != j && b[j] == a[k]
dp[i][j][0] += dp[i - a[j]][k][1], k != j && b[j] == b[k]
dp[i][j][1] += dp[i - b[j]][k][0], k != j && a[j] == a[k]
dp[i][j][1] += dp[i - b[j]][k][1], k != j && a[j] == b[k]
如何初始化？所有的 dp[a[i]][i][0] = 1, dp[b[i]][i][1] = 1，然后记忆化搜索
*/

int dp[M][N][2], a[N], b[N], n, l;

int dfs(int i, int j, int rev) {
    if (dp[i][j][rev] >= 0) {
        return dp[i][j][rev];
    }
    dp[i][j][rev] = 0;
    int mod = 1e9 + 7;
    if (rev == 0) {
        for (int k = 1; k <= n; k++) {
            if (k != j && i > a[j]) {
                if (b[j] == a[k]) {
                    dfs(i - a[j], k, 0);
                    dp[i][j][0] += dp[i - a[j]][k][0];
                    dp[i][j][0] %= mod;
                }
                if (b[j] == b[k] && a[k] != b[k]) {
                    dfs(i - a[j], k, 1);
                    dp[i][j][0] += dp[i - a[j]][k][1];
                    dp[i][j][0] %= mod;
                }
            }
        }
    } else {
        for (int k = 1; k <= n; k++) {
            if (k != j && i > b[j]) {
                if (a[j] == a[k]) {
                    dfs(i - b[j], k, 0);
                    dp[i][j][1] += dp[i - b[j]][k][0];
                    dp[i][j][1] %= mod;
                }
                if (a[j] == b[k] && a[k] != b[k]) {
                    dfs(i - b[j], k, 1);
                    dp[i][j][1] += dp[i - b[j]][k][1];
                    dp[i][j][1] %= mod;
                }
            }
        }
    }
    return dp[i][j][rev];
}

void meibao() {
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    int mod = 1e9 + 7;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++) {
        dp[a[i]][i][0] = 1;
        if (a[i] != b[i]) {
            dp[b[i]][i][1] = 1;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += dfs(l, i, 0);
        res %= mod;
        if (a[i] != b[i]) {
            res += dfs(l, i, 1);
            res %= mod;
        }
    }
    cout << res << "\n";
}
