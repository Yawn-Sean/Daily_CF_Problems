/*
至多 kr kg kb 个（记为 cnt[0/1/2]）连续颜色一样的，排成 n 个
dp[i][0/1/2] 为前 i 个，第 i 个填 0/1/2 颜色的方案数
枚举上一个颜色的不同点：
dp[i][0] += dp[j][1/2], i - j <= cnt[0], j <= i - 1
dp[i][1] += dp[j][0/2], i - j <= cnt[1], j <= i - 1
dp[i][2] += dp[j][0/1], i - j <= cnt[2], j <= i - 1
维护前缀和即可
记得最后调整成正数的结果输出
*/

LL dp[3], s[N][3], n, cnt[3];
const int mod = 1e9 + 7;

void meibao() {
    cin >> n >> cnt[0] >> cnt[1] >> cnt[2];

    s[1][0] = s[1][1] = s[1][2] = 1;
    dp[0] = dp[1] = dp[2] = 1;
    for (int i = 2; i <= n; i++) {
        dp[0] = dp[1] = dp[2] = 0;
        int j;
        j = max(i - cnt[0], 0LL);
        dp[0] += s[i - 1][1] - s[(j >= 1 ? (j - 1) : 0)][1];
        dp[0] += s[i - 1][2] - s[(j >= 1 ? (j - 1) : 0)][2];
        if (j == 0) {
            dp[0]++;
        }
        dp[0] %= mod;

        j = max(i - cnt[1], 0LL);
        dp[1] += s[i - 1][0] - s[(j >= 1 ? (j - 1) : 0)][0];
        dp[1] += s[i - 1][2] - s[(j >= 1 ? (j - 1) : 0)][2];
        if (j == 0) {
            dp[1]++;
        }
        dp[1] %= mod;

        j = max(i - cnt[2], 0LL);
        dp[2] += s[i - 1][0] - s[(j >= 1 ? (j - 1) : 0)][0];
        dp[2] += s[i - 1][1] - s[(j >= 1 ? (j - 1) : 0)][1];
        if (j == 0) {
            dp[2]++;
        }
        dp[2] %= mod;
        
        s[i][0] = (s[i - 1][0] + dp[0]) % mod;
        s[i][1] = (s[i - 1][1] + dp[1]) % mod;
        s[i][2] = (s[i - 1][2] + dp[2]) % mod;
    }

    cout << ((dp[0] + dp[1] + dp[2]) % mod + mod) % mod;
}   
