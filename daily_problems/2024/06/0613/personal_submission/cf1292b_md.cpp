// 0613
#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x0, y0, ax, ay, bx, by;
    std::cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    i64 xs, ys, t;
    std::cin >> xs >> ys >> t;

    std::vector<std::pair<i64, i64>> points;
    auto x = x0;
    auto y = y0;
    while (x + y - xs - ys <= t) {
        points.emplace_back(x, y);
        x = ax * x + bx;
        y = ay * y + by;
    }

    const int n = ssize(points);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto[ix, iy] = points[i];
        const auto dis_from_start_to_i = abs(ix - xs) + abs(iy - ys);
        for (int left = 0; left <= i; ++left) {
            auto[lx, ly] = points[left];
            for (int right = i; right < n; ++right) {
                auto[rx, ry] = points[right];
                auto dis_all = rx + ry - lx - ly;
                auto dis_from_i_to_ends = std::min(ix + iy - lx - ly, rx + ry - ix- iy);
                if (t >= dis_from_start_to_i + dis_all + dis_from_i_to_ends) {
                    ans = std::max(ans, right - left + 1);
                }
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}