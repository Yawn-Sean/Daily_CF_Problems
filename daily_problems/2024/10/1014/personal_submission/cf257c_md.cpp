// 1014
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        points[i] = {x, y};
    } 

    std::vector<long double> angles(n);
    std::transform(begin(points), end(points), begin(angles), [](const auto& p) {
        return atan2l(p.second, p.first);
    });

    std::sort(begin(angles), end(angles));

    long double ans = 0;
    long double pi = atan2l(0, -1);
    for (int i = 1; i < n; ++i) {
        ans = std::max(ans, angles[i] - angles[i - 1]);
    }

    std::cout << std::setprecision(10) << std::fixed << std::min(2 * pi - ans, angles.back() - angles.front()) / pi * 180 << '\n';

    return 0;
}