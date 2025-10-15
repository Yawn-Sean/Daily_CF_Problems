#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 4>> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][0]--, a[i][1]--;
        a[i][3] = (i == 0 ? 1 : -1);
    }

    auto check = [&](int t) {
        DSU dsu(n);
        auto tmp = a;
        tmp[0][2] = t;

        std::ranges::sort(tmp, [](auto &x, auto &y) {
            if (x[2] != y[2]) {
                return x[2] < y[2];
            }
            return x[3] > y[3];
        });

        for (int i = 0; i < m; i++) {
            if (dsu.merge(tmp[i][0], tmp[i][1])) {
                if (tmp[i][3] == 1) {
                    return false;
                }
            }
        }

        return true;
    };

    int lo = 0, hi = inf;
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

    std::cout << (ans == -1 ? inf : ans - 1) << "\n";

    return 0;
}
