#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int la, ra, ta, lb, rb, tb;
    std::cin >> la >> ra >> ta >> lb >> rb >> tb;

    int len = la - lb;
    int g = std::gcd(ta, tb);
    len = (len % g + g) % g;

    std::cout << std::max({0, std::min(len + ra - la + 1, rb - lb + 1) - len, std::min(len + ra - la + 1 - g, rb - lb + 1)});
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