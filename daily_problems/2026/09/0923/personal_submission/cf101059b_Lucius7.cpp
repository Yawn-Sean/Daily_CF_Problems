#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::map<int, std::vector<int>> wh;
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        wh[x].push_back(i);
    }


    int ans = 1E18;
    for (auto [_, v] : wh) {
        int mx = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            int x = v[i], y = v[(i + 1) % n];
            mx = std::max(mx, ((y - 1 + N) % N - x + N) % N);
        }
        // std::cout << mx << "\n";
        ans = std::min(ans, mx + N);
    }
    std::cout << ans << "\n";
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
