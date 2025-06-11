#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> cnt(n);
    
    int res = 0;

    for (int i = 0, a; i < n; ++ i) {
        std::cin >> a;
        if (i + 1 == s)
            res += (a > 0);
        else
            ++ cnt[a];
    }

    for (int i = 1, s = 0; s + 1 < n; ++ i) {
        if (cnt[i]) s += cnt[i];
        else ++ res, ++ s;
    }

    std::cout << res;
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