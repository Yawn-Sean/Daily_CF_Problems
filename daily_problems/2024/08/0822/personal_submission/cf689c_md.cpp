// 0822
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;
    i64 lo = 8;
    i64 hi = 8 * n;

    auto check = [&](i64 x) -> i64 {
        i64 res = 0;
        for (i64 i = 2; i * i * i <= x; ++i) {
            res += x / i / i / i;
        }
        return res;
    };

    while (lo + 1 < hi) {
        i64 mid = lo + (hi - lo) / 2;
        if (check(mid) < n) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    if (check(lo) == n) {
        std::cout << lo << '\n';
    } else if (check(hi) == n) {
        std::cout << hi << '\n';
    } else {
        std::cout << -1 << '\n';
    }

    return 0;
}