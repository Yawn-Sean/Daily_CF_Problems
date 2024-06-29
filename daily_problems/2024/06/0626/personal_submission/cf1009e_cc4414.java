// https://codeforces.com/problemset/submission/1009/267478641
class Solution {
    public long solve(long[] a) {
        long mod = 998244353;
        int n = a.length;
        long[] dp = new long[n + 1];
        long p = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 2 * dp[i - 1] + p + a[i - 1];
            dp[i] %= mod;
            p *= 2;
            p += a[i - 1];
            p %= mod;
        }
        return (dp[n] % mod + mod) % mod;
    }
}
