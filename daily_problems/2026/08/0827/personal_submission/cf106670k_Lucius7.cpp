#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> r(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    int minr = *std::min_element(r.begin(), r.end()), minc = *std::min_element(c.begin(), c.end());
    int sumr = std::accumulate(r.begin(), r.end(), 0LL), sumc = std::accumulate(c.begin(), c.end(), 0LL);

    std::cout << std::min({r.front() + c.back(), r.back() + c.front(), c.front() + c.back() + minr, r.front() + r.back() + minc, sumr, sumc}) << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
