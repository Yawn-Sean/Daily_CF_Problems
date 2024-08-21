#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1e-9;

constexpr int P = 998244353;
/*
    9       9
    90      99
    900     999
    9000    9999
    ...
*/
constexpr int B = 12;
void solve() {
    i64 k;
    std::cin >> k;
    
    if (k < 10) {
        std::cout << k;
        return;
    }


    std::vector<i64> f(B), g(B);
    i64 t = 9;
    for (int i = 1; i < B; ++ i) {
        f[i] = t * i + f[i - 1];
        g[i] = g[i - 1] * 10 + 9;
        t *= 10;     
    }
    int lo = 0, hi = B;
    while (lo + 1 < hi) {
        int x = lo + hi >> 1;
        if (f[x] <= k)
            lo = x;
        else
            hi = x;            
    }
    k -= f[lo];
    
    if (!k) {
        std::cout << 9;
        return;
    }
    if (k % (lo + 1) == 0) {
        std::cout << (k / (lo + 1) - 1) % 10 << '\n';
        return;
    }

    i64 a = k / (lo + 1) + g[lo] + 1, b = lo + 1 - (k % (lo + 1));
    while (b --)
        a /= 10;
    std::cout << a % 10;
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
