#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> pos(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            x--;
            pos[x] = {i, j};
        }
    }

    std::vector<int> rcnt(n), ccnt(n);
    int sum = 0;
    for (int i = 0; i < n * n; i++) {
        auto [x, y] = pos[i];
        sum += rcnt[x] * ccnt[y];
        rcnt[x]++;
        ccnt[y]++;
    }

    std::cout << n * (n - 1) / 2 * n * (n - 1) - sum << "\n";
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
