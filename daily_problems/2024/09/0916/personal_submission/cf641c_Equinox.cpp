#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;
constexpr int inf32 = 1E9 + 7;

void solve() {
    int n, q;
    std::cin >> n >> q;

    int d0 = 0, d1 = 0, f = 0;
    for (int i = 0, op, x; i < q; ++ i) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> x;
            d0 += x, d1 += x;
            if (d0 >= n) d0 -= n;
            if (d1 >= n) d1 -= n;
            if (d0 < 0) d0 += n;
            if (d1 < 0) d1 += n;
            f ^= (x & 1);
        }
        else {
            if (f) ++ d0, -- d1;
            else -- d0, ++ d1;
            f ^= 1;
        }
    }

    std::vector<int> ans(n);
    for (int i = 0; i < n; ++ i) {
        if (i & 1)
            ans[(i + d0) % n] = i + 1;
        else
            ans[(i + d1) % n] = i + 1;
    }
    for (int i = 0; i < n; ++ i)
        std::cout << ans[i] << " \n"[i + 1 == n];
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