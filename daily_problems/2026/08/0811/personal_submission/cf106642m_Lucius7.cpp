#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::map<int, int> u, v;
    std::map<std::pair<int, int>, int> w;
    for (int i = 0; i < n; i++) {
        u[a[i] + b[i]]++;
        v[a[i] - b[i]]++;
        w[{a[i], b[i]}]++;
    }

    int ans = 0;
    for (auto [_, cnt] : u) {
        ans += (cnt - 1) * cnt / 2;
    }
    for (auto [_, cnt] : v) {
        ans += (cnt - 1) * cnt / 2;
    }
    for (auto [_, cnt] : w) {
        ans -= (cnt - 1) * cnt / 2;
    }

    std::cout << ans << "\n";
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
