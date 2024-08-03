/*
第 i 种颜色有 a[i] 个球，需要至少分到 a[i] 个 group 中
假设选了一些颜色，这些颜色的球总共有 cnt 个
至少分 max((cnt + 1) / 2, max(a[i])) 组
所有球加起来不超过 5000 个，不超过 5000 种颜色，每种颜色至少 1 个球，奇怪的限制
枚举每个颜色的球，看其在多少个集合中是最多的
把 a 排个序，则前 i 个颜色中强制选 i，i 就是最多的
dp[i][j]: 前 i 种颜色中选一些颜色，共选出了恰好 j 个球的方案数
对于 0 <= j <= a[i]，dp[i - 1][j] 就是前 i - 1 种颜色选不超过 a[i] 个球的方案
这种情况的贡献就是 dp[i - 1][j] * a[i]
对于 a[i] < j < 5000 的，dp[i - 1][j] 就是前 i - 1 种颜色选超过 a[i] 个球的方案
这种情况贡献是 dp[i - 1][j] * (j + a[i] + 1) / 2
*/

int T;
LL dp[N], n, a[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    LL res = 0;
    dp[0] = 1;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= a[i]; j++) {
            res += dp[j] * a[i];
            res %= MOD2;
        }
        for (int j = a[i] + 1; j < N; j++) {
            res += dp[j] * ((j + a[i] + 1) / 2);
            res %= MOD2;
        }
        for (int j = N - 1; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
            dp[j] %= MOD2;
        }
    }
    cout << res << endl;
}                                                                                                                  
