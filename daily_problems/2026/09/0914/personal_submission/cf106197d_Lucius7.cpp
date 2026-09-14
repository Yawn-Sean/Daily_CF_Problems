#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;

    std::string ans;
    for (int i = 0; i < n; i++) {
        if (k & 1) {
            if (s[i] == '+') {
                k -= 1;
            } else {
                k += 1;
            }
            ans += '#';
        } else {
            ans += '.';
        }
        k /= 2;
    }

    if (k) {
        std::cout << "-1\n";
    } else {
        std::cout << ans << "\n";
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
