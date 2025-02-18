// 1025
#include <bits/stdc++.h>

using i64 = long long;
constexpr int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> pis(n);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        pis[i] = x - 1;
    }

    std::vector<i64> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = (dp[i - 1] * 2) % MOD;
        dp[i] = (dp[i] - dp[pis[i - 1]] + MOD + 2) % MOD;
    }
    std::cout << dp[n] << '\n';
    return 0;
}