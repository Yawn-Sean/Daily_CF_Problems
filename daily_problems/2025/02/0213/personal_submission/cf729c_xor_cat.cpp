#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, s, t;
    std::cin >> n >> k >> s >> t;

    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
    }
    std::ranges::sort(a, [](auto &x, auto &y) {
        if (x[1] != y[1]) {
            return x[1] < y[1];
        }
        return x[0] < y[0];
    });

    std::vector<i64> g(k + 2);
    g[0] = 0;
    g[k + 1] = s;
    for (int i = 1; i <= k; i++) {
        std::cin >> g[i];
    }
    std::ranges::sort(g);

    auto check = [&](int m) {
        i64 res = 0, v = a[m][1];
        for (int i = 0; i <= k; i++) {
            i64 d = g[i + 1] - g[i];
            if (d > v) {
                return false;
            }
            res += 2 * d - std::min(v - d, d);
        }
        return res <= t;
    };

    int lo = 0, hi = n - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    if (ans == -1) {
        std::cout << -1 << "\n";
    } else {
        int min = a[ans][0];
        for (int i = ans + 1; i < n; i++) {
            chmin(min, a[i][0]);
        }
        std::cout << min << "\n";
    }

    return 0;
}
