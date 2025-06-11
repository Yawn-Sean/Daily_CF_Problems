#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1'000'000'007;

void solve() {
    i64 n, l, r;

    std::cin >> n >> l >> r;

    auto dfs = [&](auto &&self, i64 x, i64 l, i64 r) -> int {
        if (x < 2) return x;
        i64 sz = 63 - __builtin_clzll(x);
        i64 len = (1LL << sz) - 1;

        i64 res = 0;

        if (l < len) res += self(self, x / 2, l, std::min(len - 1, r));
        if (l <= len && len <= r) res += (x & 1);
        if (r > len) res += self(self, x / 2, std::max(0LL, l - len - 1), r - len - 1);
        return res;
    };

    std::cout << dfs(dfs, n, l - 1, r - 1);
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