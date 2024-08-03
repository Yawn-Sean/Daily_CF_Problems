/*
dp[i]: 从 i 变成 1 的方案数
dp[i] += dp[j], 1 <= j < i，前缀和
dp[i] += dp[i / j], 1 <= j < i，整除分块
*/

int T;
LL dp[N], s[N], n, mod;

void solve1() {
    cin >> n >> mod;
    dp[1] = 1;
    s[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] += s[i - 1];
        dp[i] %= mod;
        for (LL l = 2, r; l <= i; l = r + 1) {
            LL k = i / l;
            r = i / k;
            dp[i] += (r - l + 1) * dp[k] % mod;
            dp[i] %= mod;
        }
        s[i] = s[i - 1] + dp[i];
        s[i] %= mod;
    }
    cout << dp[n] << "\n";
}        