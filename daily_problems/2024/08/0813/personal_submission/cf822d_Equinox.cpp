#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1E-9;
constexpr int P = 1'000'000'007;

void solve() {
    int t, l, r;

    std::cin >> t >> l >> r;

    std::vector<i64> f(r + 1, inf64);

    f[1] = 0;

    for (int i = 1; i <= r; ++ i) {
        for (int j = 2; j * i <= r; ++ j) {
            f[i * j] = std::min(f[i * j], f[i] + 1LL * j * (j - 1) / 2 * i);
        }
    }

    int res = 0;

    for (int i = l, s = 1; i <= r; ++ i) {
        f[i] %= P;
        res = (res + s * f[i] % P) % P;
        s = 1LL * s * t % P;
    }

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
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}