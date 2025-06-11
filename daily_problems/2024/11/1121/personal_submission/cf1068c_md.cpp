// 1121
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> grid(n + 1);
    for (int i = 1; i <= n; ++i) {
        grid[i].push_back({i, i});
    }

    for (int i = 1; i <= m; ++i) {
        int a, b;
        std::cin >> a >> b;
        grid[a].push_back({n + i, a});
        grid[b].push_back({n + i, b});
    }

    for (const auto& row : grid) {
        if (size(row) == 0) {
            continue;
        }

        std::cout << size(row) << '\n';
        for (const auto& [a, b] : row) {
            std::cout << a << ' ' << b << '\n';
        }
    }

    return 0;
}