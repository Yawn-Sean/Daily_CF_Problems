#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;

    int pre = 0, sum = 0;
    std::vector<int> ans(n);
    auto check = [&](int i, int m) {
        i128 npre = pre + m;
        i128 nsum = sum;

        i128 u = (npre > 0 ? npre : -npre);
        i128 steps = (u + k - 1) / k;

        int a = (u % k == 0 ? k : u % k);
        nsum += (u + a) * steps / 2;
        return steps <= n - 1 - i && nsum <= x;
    };

    
    for (int i = 0; i < n; i++) {
        int lo = std::max(-k, -x), hi = std::max(-k, std::min(k, -pre));
        while (lo < hi) {
            int m = (lo + hi) >> 1;
            if (check(i, m)) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }

        ans[i] = lo;
        pre += lo;
        sum += std::abs(pre);
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
