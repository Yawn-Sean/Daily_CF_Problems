#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;
    
    bool f = true;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            f = false;
            break;
        }
    }

    if (f) {
        std::cout << n << "\n";
        return;
    }


    int u = ((std::count(s.begin(), s.end(), 'V') - std::count(s.begin(), s.end(), 'G')) % 3 + 3) % 3;
    if (u == 0) {
        std::cout << 2 << "\n";
    } else {
        std::cout << 1 << "\n";
    }

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
