// 1029
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> costs(n, std::vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> costs[j][i];
        }
    }

    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(2, std::numeric_limits<int>::min()));
    dp[1][0] = 0;
    for (int i = 2; i <= n + 1; ++i) {
        dp[i][1] = std::max(dp[i - 1][1] + costs[i - 2][1], dp[i - 1][0] + costs[i - 2][0]);
        dp[i][0] = std::max(dp[i - 1][1] + costs[i - 2][2], dp[i - 1][0] + costs[i - 2][1]);
    }

    std::cout << dp[n + 1][1] << '\n';
    return 0;
}   