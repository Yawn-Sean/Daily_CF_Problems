// 0718
#include <bits/stdc++.h>

using i64 = long long;
constexpr int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int max_len = 100;
    auto cnt = max_len * 25;
    // dp[len][prefix_sum]
    // dp[l][s] = dp[l - 1][s - 1] + dp[l - 1][s - 2] + ... + dp[l - 1][s - 25]
    std::vector<std::vector<i64>> dp(max_len + 1, std::vector<i64>(cnt + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= max_len; ++i) {
        std::vector<i64> acc(cnt + 2);
        std::partial_sum(begin(dp[i - 1]), end(dp[i - 1]), next(begin(acc)), [](auto&& acc, auto&& val) {
            return (acc + val) % MOD;
        });

        for (int j = 0; j <= cnt; ++j) {
            dp[i][j] = (acc[j + 1] - acc[std::max(j - 25, 0)] + MOD) % MOD;
        }
    }

    int t = 0;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;

        auto ch_sum = std::accumulate(begin(s), end(s), 0, [](auto&& acc, int x) {
            return std::move(acc) + x - 'a';
        });

        auto len = size(s);
        i64 ans = dp[len][ch_sum] - 1;
        if (ans < 0) {
            ans += MOD;
        }
        std::cout << ans % MOD << '\n';
    }

    return 0;
}