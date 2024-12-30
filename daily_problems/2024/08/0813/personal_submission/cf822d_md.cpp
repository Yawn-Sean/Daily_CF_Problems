// 0813
#include <bits/stdc++.h>
using i64 = long long;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    constexpr int mod = 1e9 + 7;
    constexpr int n = 5e6 + 1;
    std::array<i64, n> dp{ 0 };
    memset(dp.data(), 0x3f, sizeof(i64) * n);
 
    dp[1] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 2; j * i < n; ++j) {
            dp[i * j] = std::min(dp[i * j], dp[i] + (i64)j * (j - 1) / 2 * i);
        }
    }
 
    int t, l, r;
    std::cin >> t >> l >> r;
    i64 ret = 0;
    i64 tc = 1;
    for (int i = l; i <= r; ++i) {
        ret = (ret + dp[i] % mod * tc % mod) % mod;
        tc = tc * t % mod;
    }
    std::cout << ret << '\n';
 
    return 0;
}