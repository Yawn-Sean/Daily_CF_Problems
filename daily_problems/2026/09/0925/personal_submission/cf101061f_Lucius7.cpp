#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    constexpr int inf = 1E9;
    std::vector<int> dp(1E4 + 10, inf);
    int sum = 0;
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        std::vector<int> ndp(1E4 + 10, inf);
        for (int x = 0; x <= 1E4; x++) {
            if (dp[x] != inf) {
                int y = sum - x;
                ndp[x] = std::min(ndp[x], std::max(dp[x], std::abs(x - (y + a[i]))));
                ndp[x + a[i]] = std::min(ndp[x + a[i]], std::max(dp[x], std::abs(x + a[i] - y)));
            }
        }
        dp = std::move(ndp);
        sum += a[i];
    }

    std::cout << *std::min_element(dp.begin(), dp.end()) << "\n";
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
