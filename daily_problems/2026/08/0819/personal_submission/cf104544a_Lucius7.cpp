#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] = std::__gcd(a[i], x);
    }

    std::vector<int> divs;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i * i == x) {
                divs.push_back(i);
            } else {
                divs.push_back(i);
                divs.push_back(x / i);
            }
        }
    }
    std::sort(divs.begin(), divs.end());
    const int k = divs.size();

    auto pos = [&](int x) {
        return std::distance(divs.begin(), std::lower_bound(divs.begin(), divs.end(), x));
    };

    std::vector<int> cnt(k);
    for (int i = 0; i < n; i++) {
        cnt[pos(a[i])]++;
    }

    std::vector nxt(k, std::vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            nxt[i][j] = pos(divs[i] * std::__gcd(divs[j], x / divs[i]));
        }
    }

    constexpr int inf = 1E8;
    std::vector<int> dp(k, inf);
    dp[0] = 0;
    for (int i = 0; i < k; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        int times = std::min(cnt[i], 40LL);
        while (times--) {
            auto ndp = dp;
            for (int j = 0; j < k; j++) {
                if (ndp[nxt[i][j]] > dp[j] + 1) {
                    ndp[nxt[i][j]] = dp[j] + 1;
                }
            }
            dp = std::move(ndp);
        }
    }
    std::cout << (dp.back() == inf ? -1 : dp.back()) << "\n";

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
