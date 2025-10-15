#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1E9;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> X, Y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'B') {
                X.push_back(i + j);
                Y.push_back(j - i);
            }
        }
    }
    std::ranges::sort(X);
    std::ranges::sort(Y);

    auto get = [&](int x, int y) {
        return std::max({x - X.front(), y - Y.front(), X.back() - x, Y.back() - y});
    };

    std::array<int, 4> ans{inf, inf, inf, inf};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = i + j;
            int y = j - i;
            if (get(x, y) < get(ans[0], ans[1])) {
                ans = {x, y, i, j};
            }
        }
    }
    std::cout << ans[2] + 1 << " " << ans[3] + 1 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
