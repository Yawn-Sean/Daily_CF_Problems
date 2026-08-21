#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int w, l;
    std::cin >> w >> l;

    std::set<int> s;
    s.insert(2);
    for (auto [x, y] : (std::vector<std::pair<int, int>>){{w - 1, l - 1}, {w, l - 2}, {w - 2, l}}) {
        int g = std::__gcd(x, y);
        s.insert(g);
        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                s.insert(i);
                s.insert(g / i);
            }
        }
    }
    std::cout << s.size() << " ";
    for (auto x : s) {
        std::cout << x << " ";
    }
    std::cout << "\n";
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
