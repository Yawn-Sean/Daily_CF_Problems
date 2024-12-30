/*
大小为 k 的粒子在 n 个平面都留下一个反向的 k - 1 粒子
似乎可以 DP，转化为规模更小的问题，主要是 k 会减小，最后变成 1
考虑粒子等级，发射需要穿过的平面个数
dp[i][j] = dp[i - 1][j] + dp[n - i][j - 1]
*/

int T;
int n, k;
LL dp[N][N];

void solve1() {
    memset(dp, 0, sizeof dp);
    cin >> n >> k;
    for (int j = 1; j <= k; j++) {
        dp[0][j] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][j] = (dp[i - 1][j] + dp[n - i][j - 1]) % MOD1;
        }
    }
    cout << dp[n][k] << "\n";
}       
