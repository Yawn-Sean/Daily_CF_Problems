#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> votes(m, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> votes[i][j];
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            votes[j][i] = votes[j][n - 1] - votes[j][i];
        }
    }

    int ret = m;
    int uid = -1;
    for (int i = 0; i < n - 1; ++i) {
        std::vector<int> tickets(m);
        for (int j = 0; j < m; ++j) {
            tickets[j] = votes[j][i];
        }

        std::sort(begin(tickets), end(tickets));
        std::partial_sum(begin(tickets), end(tickets), begin(tickets));

        auto keep = std::upper_bound(begin(tickets), end(tickets), 0) - begin(tickets);
        if (m - keep < ret) {
            ret = m - keep;
            uid = i;
        }
    }

    std::cout << ret << '\n';
    if (uid == -1) {
        for (int j = 1; j <= m; ++j) {
            std::cout << j << ' ';
        }
    } else {
        std::vector<std::pair<int, int>> tickets(m);
        for (int j = 0; j < m; ++j) {
            tickets[j] = {votes[j][uid], j + 1};
        }

        std::sort(begin(tickets), end(tickets));
        for (int j = m - ret; j < m; ++j) {
            std::cout << tickets[j].second << ' ';
        }
    }

    return 0;
}