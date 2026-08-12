#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int a, b;
    std::cin >> a >> b;

    std::vector<int> v;
    while(b) {
        v.push_back(b % (a + 1));
        b /= (a + 1);
    }

    std::cout << v.size() << "\n";
    for (auto x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";
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
