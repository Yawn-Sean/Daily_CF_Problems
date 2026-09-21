#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;
    

    std::multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        s.insert(x);
    }

    int ans = 0;
    while (s.size() >= 2) {
        std::multiset<int> ns;

        while (s.size()) {
            auto a = s.begin();
            auto b = s.end();
            b--;
            ans += *b - *a;
            ns.insert(*b);
            // std::cout << *a << " " << *b << "\n";
            s.erase(a);
            s.erase(b);   
        }

        s = std::move(ns);
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
