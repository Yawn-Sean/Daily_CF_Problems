#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
constexpr int inf32 = 1e9 + 7;
constexpr i64 inf64 = 1e18 + 7;
constexpr int P = 998244353;
constexpr double eps = 1e-6;

// #define DEBUG

/*
    d | ai - ai+1
    d | ai + ai+1

    d | 2ai
    d | 2ai+1

    => d | 2
*/

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; ++ i) std::cin >> a[i], g = std::gcd(g, a[i]);
    
    if (g > 1) {
        std::cout << "YES\n0";
        return;
    }

    i64 res = 0, c = 0;
    for (int x : a) {
        if (x & 1) ++ c;
        else {
            res += c / 2 + (c & 1) * 2;
            c = 0;
        }
    }
    res += c / 2 + (c & 1) * 2;
    std::cout << "YES\n" << res;
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_--)
        solve();
    return 0;
}