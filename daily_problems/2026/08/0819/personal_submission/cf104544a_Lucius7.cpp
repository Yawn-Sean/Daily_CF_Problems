#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using real = long double;

void solve() {
    real x, y, z;
    std::cin >> x >> y >> z;
    
    real tx, ty, tz;
    std::cin >> tx >> ty >> tz;

    real r;
    std::cin >> r;

    auto check = [&](real t) {
        real mx = 0;
        for (auto cx : {t, x - t}) {
            for (auto cy : {t, y - t}) {
                for (auto cz : {t, z - t}) {
                    real dx = cx - tx, dy = cy - ty, dz = cz - tz;
                    mx = std::max(mx, dx * dx + dy * dy + dz * dz);
                }
            }
        }
        return mx >= (r + t) * (r + t);
    };

    constexpr real eps = 1E-10;
    real lo = 0, hi = std::min({x, y, z}) / 2.0;
    for (int _ = 0; _ < 1000; _++) {
        real m = (lo + hi) / 2;
        if (check(m)) {
            lo = m;
        } else {
            hi = m;
        }
    }
    std::cout << std::fixed << std::setprecision(15) << lo << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
