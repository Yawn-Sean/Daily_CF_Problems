// 0803
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q, c;
    std::cin >> n >> q >> c;

    using board_t = std::vector<std::vector<int>>;
    std::vector<board_t> cnt(c + 1, board_t(101, std::vector<int>(101, 0))); 
    for (int i = 0; i < n; ++i) {
        int x, y, s;
        std::cin >> x >> y >> s;
        for (int rnd = 0; rnd <= c; ++rnd) {
            cnt[rnd][x][y] += (s + rnd) % (c + 1);
        }
    }

    std::vector<board_t> sum(c + 1, board_t(101, std::vector<int>(101, 0))); 
    for (int rnd = 0; rnd <= c; ++rnd) {
        for (int i = 1; i <= 100; ++i) {
            int row_sum = 0;
            for (int j = 1; j <= 100; ++j) {
                row_sum += cnt[rnd][i][j];
                sum[rnd][i][j] = row_sum + sum[rnd][i - 1][j];
            }
        }
    }

    while (q--) {
        int t, x1, y1, x2, y2;
        std::cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= (c + 1);
        int cur_sum = sum[t][x2][y2] - sum[t][x1 - 1][y2] - sum[t][x2][y1 - 1] + sum[t][x1 - 1][y1 - 1];
        std::cout << cur_sum << '\n';
    }

    return 0;
}