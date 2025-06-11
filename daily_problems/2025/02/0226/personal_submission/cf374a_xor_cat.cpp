#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <typename T>
bool chmin(T &a, const T &b) {
    return b < a ? a = b, true : false;
}
template <typename T>
bool chmax(T &a, const T &b) {
    return b > a ? a = b, true : false;
}

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, i, j, a, b;
    std::cin >> n >> m >> i >> j >> a >> b;

    // (1, 1), (n, m), (n, 1), (1, m)
    std::set<std::pair<int, int>> corner =
        {{1, 1}, {n, m}, {n, 1}, {1, m}};

    if (corner.contains({i, j})) {
        std::cout << 0 << "\n";
        return 0;
    }

    int ans = inf;
    auto check = [&](int dx, int dy) {
        if (dx % a == 0 && dy % b == 0) {
            if ((dx / a) % 2 == (dy / b) % 2) {
                chmin(ans, std::max(dx / a, dy / b));
            }
        }
    };

    for (auto &[x, y] : corner) {
        check(std::abs(i - x), std::abs(j - y));
    }

    if (ans == inf || a >= n || b >= m) {
        std::cout << "Poor Inna and pony!\n";
    } else {
        std::cout << ans << "\n";
    }

    return 0;
}
