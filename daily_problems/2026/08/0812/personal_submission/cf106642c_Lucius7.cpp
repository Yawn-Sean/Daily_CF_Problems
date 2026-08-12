#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::array<int, 2>> nxt(m, {n, n});
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        std::vector<int> v;
        for (int j = 0; j < m; j++) {
            if ((a[i] >> j) & 1) {
                v.push_back(nxt[j][0]);
                nxt[j][1] = i;
            } else {
                v.push_back(nxt[j][1]);
                nxt[j][0] = i;
            }
        }
        std::sort(v.begin(), v.end());
        if (k == 0) {
            // std::cout << v[0] - i << " ";
            ans += v[0] - i;
        } else if (k == m) {
            // std::cout << n - v[m - 1] << " ";
            ans += n - v[m - 1];
        } else {
            // std::cout << v[k] - v[k - 1] << " ";
            ans += v[k] - v[k - 1];
        }
    }
    // std::cout << "\n";
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
