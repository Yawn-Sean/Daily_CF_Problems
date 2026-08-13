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

    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        if (a[i] != 1) {
            v.push_back(a[i]);
        } 
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == v[(i + 1) % v.size()]) {
            std::cout << "NO\n";
            return;
        }
    }

    if (v.empty()) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
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
