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

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> w(m);
    for (int i = 0, q; i < m; ++ i)
        std::cin >> q >> w[i];

    std::sort(w.begin(), w.end(), std::greater<int>());

    i64 res = 0;
    for (i64 i = 1; i <= m; ++ i) {
        if (i * (i - 1) / 2 + (i % 2 == 0) * (i - 2) / 2 > n - 1) break;
        res += w[i - 1];
    }

    std::cout << res;
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