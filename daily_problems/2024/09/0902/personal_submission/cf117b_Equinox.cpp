#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int a, b, mod;
    std::cin >> a >> b >> mod;
    int p = 1E9;

    for (int i = 0, ed = std::min(a, mod); i <= ed; ++ i) {
        int x = (mod - 1LL * i * p % mod) % mod; 
        if (x > b) {
            std::cout << 1 << ' ';
            std::string ans = std::to_string(i);
            std::cout << std::string(9 - ans.size(), '0') + ans;
            return;
        }
    }

    std::cout << 2;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}