#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;
using PII = std::pair<int, int>;
constexpr int inf32 = 1e9 + 7;
constexpr i64 inf64 = 1e18 + 7;
constexpr int P = 998244353;


// #define DEBUG

void solve()
{
    int n;
    std::cin >> n;
    int ans = n;
    std::vector<int> d(n, 1);
    for (int i = 1, u, v; i < n; ++ i) {
        std::cin >> u >> v;
        -- u, -- v;
        ans = 1LL * ans * d[u] % P * d[v] % P;
        ++ d[u], ++ d[v];
    }
    std::cout << ans;
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