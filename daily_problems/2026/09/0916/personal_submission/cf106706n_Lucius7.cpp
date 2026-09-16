#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i].first;
        x[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> y[i].first;
        y[i].second = i;
    }

    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end(), std::greater<>());

    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[x[i].second] = y[i].second;
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
    }
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
