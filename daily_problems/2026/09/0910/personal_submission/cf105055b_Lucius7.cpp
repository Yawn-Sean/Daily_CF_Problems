#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N, K;
    std::cin >> N >> K;

    std::string s;
    std::cin >> s;

    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[s.size() - 1 - i] == '1') {
            if (i % 2 == 0) {
                sum += 1;
            } else {
                sum += 2;
            }
        }
    }

    if (N % 2 == 0 && sum % 3 != 0) {
        std::cout << "GIOVANA\n";
    } else {
        std::cout << "JULIA\n";
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
