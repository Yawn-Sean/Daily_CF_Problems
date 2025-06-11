// 0716 
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ax, ay, bx, by, tx, ty;
    std::cin >> ax >> ay >> bx >> by >> tx >> ty;
    int n;
    std::cin >> n;
    std::vector<int> x(n), y(n);

    auto dis_to_bin = [&](int x, int y) {
        return std::hypot(x - tx, y - ty);
    };

    auto dis_to_a = [&](int x, int y) {
        return std::hypot(x - ax, y - ay);
    };

    auto dis_to_b = [&](int x, int y) {
        return std::hypot(x - bx, y - by);
    };

    double dis_all = 0.0;
    std::vector<double> dis_a(n), dis_b(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        dis_all += 2 * dis_to_bin(x, y);
        dis_a[i] = -dis_to_bin(x, y) + dis_to_a(x, y);
        dis_b[i] = -dis_to_bin(x, y) + dis_to_b(x, y);
    }

    std::vector<int> ids_a(n), ids_b(n);
    std::iota(begin(ids_a), end(ids_a), 0);
    std::iota(begin(ids_b), end(ids_b), 0);
    std::sort(begin(ids_a), end(ids_a), [&](auto&& lhs, auto&& rhs) {
        return dis_a[lhs] < dis_a[rhs];
    });
    std::sort(begin(ids_b), end(ids_b), [&](auto&& lhs, auto&& rhs) {
        return dis_b[lhs] < dis_b[rhs];
    });

    double offset = std::min(dis_a[ids_a[0]], dis_b[ids_b[0]]);
    if (ids_a[0] == ids_b[0]) {
        offset = std::min({offset, dis_a[ids_a[1]] + dis_b[ids_b[0]], dis_a[ids_a[0]] + dis_b[ids_b[1]]});
    } else {
        offset = std::min(offset, dis_a[ids_a[0]] + dis_b[ids_b[0]]);
    }

    std::cout << std::fixed << std::setprecision(10) << dis_all + offset << '\n';

    return 0;
}