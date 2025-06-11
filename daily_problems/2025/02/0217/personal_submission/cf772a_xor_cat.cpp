#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using real = long double;
constexpr real eps = 1E-8;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(12);

    int n, p;
    std::cin >> n >> p;

    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
    }

    auto check = [&](real t) {
        real sum = 0;
        for (auto &[x, y] : a) {
            sum += std::max<real>(x * t - y, 0);
        }
        return sum >= p * t;
    };

    int cnt = 500;
    real lo = 0, hi = 1E15;
    while (hi - lo > eps) {
        real mid = (lo + hi) / 2;
        cnt--;
        if (cnt == 0) break;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (hi >= 1E14) {
        std::cout << -1 << "\n";
    } else {
        std::cout << hi << "\n";
    }

    return 0;
}
