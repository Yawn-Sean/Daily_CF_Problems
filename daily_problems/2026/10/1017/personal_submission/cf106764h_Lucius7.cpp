#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> d(n), r(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> r[i];
    }

    std::vector<int> mr(n);
    for (int i = 0; i < n; i++) {
        mr[std::max(0LL, i - r[i])] = std::min(n - 1, std::max(mr[std::max(0LL, i - r[i])], i + r[i]));
    }
    for (int i = 1; i < n; i++) {
        mr[i] = std::max(mr[i - 1], mr[i]);
    }

    auto check = [&](int m) {
        std::vector<int> dd(n + 1);
        dd[0] = d[0];
        for (int i = 1; i < n; i++) {
            dd[i] = d[i] - d[i - 1];
        }

        int res = 0;
        if (dd[0] < m) {
            int x = m - dd[0];
            res += x;
            dd[0] += x;
            dd[mr[0] + 1] -= x;
        }
        for (int i = 1; i < n; i++) {
            dd[i] += dd[i - 1];
            if (dd[i] < m) {
                int x = m - dd[i];
                res += x;
                dd[i] += x;
                dd[mr[i] + 1] -= x;
            }
        }

        return res <= k;
    };

    int lo = 0, hi = *min_element(d.begin(), d.end()) + k + 10;
    while (lo < hi) {
        int m = (lo + hi + 1) >> 1;
        if (check(m)) {
            lo = m;
        } else {
            hi = m - 1;
        }
    }
    std::cout << lo << "\n";
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
