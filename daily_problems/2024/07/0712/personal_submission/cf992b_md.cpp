// 0712
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l, r, x, y;
    std::cin >> l >> r >> x >> y;
    if (y % x != 0) {
        std::cout << 0 << '\n';
        return 0;
    }

    y /= x;
    int ret = 0;
    for (int i = 1; i * i <= y; ++i) {
        if (y % i == 0 && std::gcd(i, y / i) == 1) {
            int v1 = i * x;
            int v2 = y / i * x;
            if (v1 < l || v1 > r || v2 < l || v2 > r) {
                continue;
            }
            ret += 1 + (v1 != v2);
        }
    }
    std::cout << ret << '\n';
    return 0;
}