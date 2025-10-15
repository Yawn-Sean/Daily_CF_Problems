/*
选一个组号 u，看目前存在的比 u 小的最大组号 v，把 u 移动到 v
之后就没有 v 组了，都是 u 组
一定不会选 1
我们合并的是目前存在的相邻的 u v
u v 之间的组号一定已经被合并没了，并且一定都是变成 u 组了
dp[i][j]: 合并从第 i 组到第 j 组的最小代价
dp[i][j] = dp[i][k] + dp[k + 1][j] + cost
其中，dp[i][k] 最后一定是在 i 的位置，dp[k + 1][j] 最后一定在 k + 1 的位置
*/

int n, a[M], cost[M][M], dp[M][M];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[a[i]][a[j]] = abs(i - j);
        }
    }

    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost[i][k + 1]);
            }
        }
    }
    cout << dp[1][n] << "\n";
}   
