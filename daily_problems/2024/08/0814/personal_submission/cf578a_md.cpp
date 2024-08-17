// 0814
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    std::cin >> x >> y;
    if (x < y) {
        std::cout << "-1\n";
        return 0;
    }

    auto getX = [&](int b) -> double {
        if (b < 2 * y) {
            return 1e9;
        }

        int x1 = b / (2 * y);
        return 1.0 * b / 2.0 / x1;
    };
    double x1 = getX(x - y);
    double x2 = getX(x + y);
    std::cout << std::fixed << std::setprecision(10) << std::min(x1, x2) << '\n';

    return 0;
}