#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;
constexpr int inf32 = 1E9 + 7;

int query(int x, int y) {
    std::cout << x << ' ' << y << std::endl;

    std::string res;
    std::cin >> res;
    return res[0] == 'w';
}

void solve() {
    int n;
    std::cin >> n;

    int lo = 0, hi = 1'000'000'000;

    int chi = query(hi, hi);
    
    -- n;

    while(n --) {
        int x = lo + hi >> 1;
        int c = query(x, x);
        if (c == chi) hi = x;
        else lo = x;
    }

    std::cout << lo << ' ' << hi << ' ' << hi << ' ' << lo << std::endl;
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