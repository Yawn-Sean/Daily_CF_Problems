// 0726
#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    int tot_one = 0;
    std::vector<std::string> board(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> board[i];
        tot_one += std::count(begin(board[i]), end(board[i]), '1');
    }

    std::vector<int> one_cnt(n);
    for (int i = 0; i < n; ++i) {
        int x = i;
        int y = 0;
        for (int j = 0; j < n; ++j) {
            one_cnt[i] += (board[x][y] == '1');
            x++;
            y++;
            if (x >= n) {
                x = 0;
            }
            if (y >= n) {
                y = 0;
            }
        }
    }
    int max_diag_ones = *std::max_element(begin(one_cnt), end(one_cnt));
    std::cout << tot_one - max_diag_ones + (n - max_diag_ones) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}