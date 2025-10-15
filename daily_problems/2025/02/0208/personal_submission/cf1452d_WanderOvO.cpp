/*
假设第一个塔在 i 位置，则其功率必须是 i，否则覆盖不全
那么下一个塔最左只能建在 2i
知道了第一个塔的位置 i，问题就变成了求 [2i, n] 有多大概率可行，即长度为 n - 2i + 1 的区间的可行概率，或许可以 dp
dp[i]: 为了使得长度为 i 的区间的每个位置都恰好被一个塔影响，有多大概率
dp[0] = 1
dp[1] = 1 / 2
dp[i] 怎么算？
第一个塔放 1 位置，则由 dp[i - 1] 转移，dp[i] += dp[i - 1] / 2
第一个塔放 2 位置，则由 dp[i - 3] 转移，dp[i] += dp[i - 3] / 2^3
第一个塔放 j 位置，则有 dp[i - 2 * j + 1] 转移，dp[i] += dp[i - 2 * j + 1] / 2^(2 * j - 1)
2 * j - 1 <= i => 2 * j <= i + 1 => j <= (i + 1) / 2
只需要维护两个变量，分别维护奇数下标和偶数下标的和
每次算完 dp[i]，加入到对应变量中，并整体除以 4
*/

LL n, dp[N], even = 0, odd = 0;

void meibao() {
    cin >> n;
    int mod = MOD2;
    dp[0] = 1;
    even = qpow(2, mod - 2, mod);
    odd = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = odd;
            even += 2 * dp[i];
            even %= mod;
            even *= qpow(4, mod - 2, mod);
            even %= mod;
        } else {
            dp[i] = even;
            odd += 2 * dp[i];
            odd %= mod;
            odd *= qpow(4, mod - 2, mod);
            odd %= mod;
        }
    }
    cout << dp[n] << "\n";
}
