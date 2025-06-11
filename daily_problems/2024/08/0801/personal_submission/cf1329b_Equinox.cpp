#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1e-9;

void solve() {
    int d, m;
    std::cin >> d >> m;
    int res = 1;
    for (int i = 0; i < 30; ++ i) {
        if (d < (1 << i))
            break;
        res = 1LL * res * (std::min<i64>((1LL << (i + 1)) - 1, d) - (1 << i) + 2) % m;
    }
    -- res;
    if (res < 0)
        res += m;
    std::cout << res << '\n';
}

auto FIO = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    std::cin >> t;
    while (t --)
        solve();

    return 0;
}