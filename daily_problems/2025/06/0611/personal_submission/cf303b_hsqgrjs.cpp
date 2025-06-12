#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
using u64 = unsigned long long;
#if defined(DEBUG)
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else 
    #define dbg(...) 42
#endif 
void solve() {
    i64 n, m, x, y, a, b;
    std::cin >> n >> m >> x >> y >> a >> b;
    i64 T = std::gcd(a, b);
    a /= T, b /= T;

    i64 k1 = n / a, k2 = m / b;
    i64 k = std::min(k1, k2);
    // dbg("k1 = %d, k2 = %d\n", k1, k2);
    i64 x1 = x - ((k * a + 1) / 2) , y1 = y - ((k * b + 1) / 2);
    if(x1 < 0) x1 = 0;
    if(y1 < 0) y1 = 0;
    if(x1 + k * a > n) x1 = n - k * a;
    if(y1 + k * b > m) y1 = m - k * b;
    i64 x2 = x1 + k * a, y2 = y1 + k * b;
    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}
