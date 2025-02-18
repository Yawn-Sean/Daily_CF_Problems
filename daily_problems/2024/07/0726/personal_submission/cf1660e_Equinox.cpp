#include <bits/stdc++.h>
#include <ranges>
#define sc scanf
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
constexpr int inf32 = 1e9 + 7;
constexpr i64 inf64 = 1e18 + 7;
constexpr int P = 1e9 + 7;
constexpr double eps = 1e-6;

// #define DEBUG

void solve()
{
    int n;
    std::cin >> n;
    int t = 0;
    std::vector<std::string> g(n);
    for (int i = 0; i < n; ++ i)
        std::cin >> g[i];

    int ma = 0;
    for (int i = 0; i < n; ++ i) {
        int s = 0;
        for (int j = 0; j < n; ++ j) {
            s += (g[j][(j + i) % n] ^ 48);
            t += (g[i][j] ^ 48);
        }
        ma = std::max(ma, s);
    }
    std::cout << n + t - ma * 2 << '\n';
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}