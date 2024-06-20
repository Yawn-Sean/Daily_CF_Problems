// 0619
#include <bits/stdc++.h>

constexpr int MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> dp(2 * n + 1, std::vector<int>(4, 0));
    // dp[n][k][c] = number of ways to color the first n cells with k connected components and the last cell is colored c
    // since dp[i][k][c] only depneds on dp[i-1][k'][c'], we can reduce the space complexity to 2 * n * O(c)
    // The meaning of values in field c, 0: BW, 1: BB, 2: WB, 3: WW
    dp[2][0] = 1;
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[1][3] = 1;

    std::vector<std::vector<int>> trans = {
        {0, 0, 2, 0},
        {1, 0, 1, 1},
        {2, 0, 0, 0},
        {1, 1, 1, 0}
    };

    for (int i = 1; i < n; ++i) {
        std::vector<std::vector<int>> ndp(2 * n + 1, std::vector<int>(4, 0));
        for (int j = 0; j <= 2 * n; ++j) {
            for (int cur_color = 0; cur_color < 4; ++cur_color) {
                for (int last_color = 0; last_color < 4; ++last_color) {
                    int j_offset = trans[last_color][cur_color];
                    if (j - j_offset >= 0) {
                        ndp[j][cur_color] += dp[j - j_offset][last_color];
                        ndp[j][cur_color] %= MOD;
                    }
                }
            }
        }

        dp = std::move(ndp);
    }

    int ret = 0;
    for (int color = 0; color < 4; ++color) {
        ret += dp[k][color];
        ret %= MOD;
    }

    std::cout << ret << '\n';

    return 0;
}