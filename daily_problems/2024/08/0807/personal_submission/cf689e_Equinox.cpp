#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1E-9;

const int P = 1'000'000'007;

int power(i64 a, i64 b) {
    int res = 1;
    for (; b; a = a * a % P, b >>= 1) {
        if (b & 1)
            res = res * a % P;
    }
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> fac(n + 1), invfac(n + 1);

    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= n; ++ i)
        fac[i] = 1LL * fac[i - 1] * i % P;

    invfac[n] = power(fac[n], P - 2);
    for (int i = n - 1; i; -- i)
        invfac[i] = (i + 1LL) * invfac[i + 1] % P;

    auto Comb = [&](int n, int m) -> int {
        return 1LL * fac[n] * invfac[m] % P * invfac[n - m] % P;
    };

    std::map<int, int> dif;

    for (int i = 0, l, r; i < n; ++ i) {
        std::cin >> l >> r;
        ++ dif[l], -- dif[r + 1];
    }

    int res = 0, cur = 0, last = 0;

    for (auto &[v, c] : dif) {
        if (cur >= k) {
            res += 1LL * (v - last) * Comb(cur, k) % P;
            if (res >= P) res -= P;
        }
        cur += c;
        last = v;
    }

    std::cout << res;
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