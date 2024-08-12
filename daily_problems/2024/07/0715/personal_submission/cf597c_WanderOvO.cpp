/*
dp[i][j]: 以 i 结尾长度为 j 的上升子序列个数
dp[i][j] += dp[k][j - 1], a[i] > a[k]
res = sum(dp[i][len + 1])
给每个长度单独开一个权值树状数组，单点加和区间和
*/

int T;
LL n, len, a[N], dp[N][M];
BIT tr[M];

void solve1() {
    cin >> n >> len;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= len + 1; i++) {
        tr[i].init(n);
    }
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = len + 1; j >= 1; j--) {
            /*
            for (int k = i - 1; k >= 0; k--) {
                if (a[i] > a[k]) {
                    dp[i][j] += dp[k][j - 1];
                }
            }
            */
            if (j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = tr[j - 1].query(a[i] - 1);
            }
            tr[j].add(a[i], dp[i][j]);
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res += dp[i][len + 1];
    }
    cout << res << "\n";
}   