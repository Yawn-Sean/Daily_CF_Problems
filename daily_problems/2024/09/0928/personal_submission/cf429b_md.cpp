// 0928
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> board(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> board[i][j];
        }
    }

    auto calc_values = [&](int xstart, int xend, int ystart, int yend) -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> dp(n, std::vector<int>(m));
        int dx = xstart < xend ? 1 : -1;
        int dy = ystart < yend ? 1 : -1;
        
        for (int i = xstart; i != xend + dx; i += dx) {
            for (int j = ystart; j != yend + dy; j += dy) {
                int v = 0;
                if (i - dx >= std::min(xstart, xend) && i - dx <= std::max(xstart, xend)) {
                    v = std::max(v, dp[i - dx][j]);
                }
                if (j - dy >= std::min(ystart, yend) && j - dy <= std::max(ystart, yend)) {
                    v = std::max(v, dp[i][j - dy]);
                }
                dp[i][j] = v + board[i][j];
            }
        }
        return dp;
    };

    auto dp_ul = calc_values(0, n - 1, 0, m - 1);
    auto dp_dl = calc_values(n - 1, 0, 0, m - 1);
    auto dp_ur = calc_values(0, n - 1, m - 1, 0);
    auto dp_dr = calc_values(n - 1, 0, m - 1, 0);

    int max_val = 0;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            max_val = std::max(max_val, dp_ul[i - 1][j] + dp_dl[i][j - 1] + dp_dr[i + 1][j] + dp_ur[i][j + 1]);
            max_val = std::max(max_val, dp_ul[i][j - 1] + dp_dl[i + 1][j] + dp_dr[i][j + 1] + dp_ur[i - 1][j]);
        }
    }

    std::cout << max_val << '\n';

    return 0;
}