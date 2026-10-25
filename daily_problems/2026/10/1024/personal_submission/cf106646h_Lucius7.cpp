#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(2 * n), b(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> b[i];
    }

    std::priority_queue<int> pq;
    int ans = a.front() - b.back();
    for (int i = 1; i < 2 * n - 1; i += 2) {
        ans -= b[i] + b[i + 1];
        pq.push(a[i] + b[i]);
        pq.push(a[i + 1] + b[i + 1]);

        auto t = pq.top();
        ans += t;
        pq.pop();
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
