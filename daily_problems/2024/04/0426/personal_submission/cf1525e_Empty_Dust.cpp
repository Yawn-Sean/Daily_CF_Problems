#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e5 + 10, inf = 1e9, mod = 998244353;
int mp[30][MAXN], n, m;
using pt = std::pair<int, int>;

i64 qpow(i64 x, i64 p)
{
    i64 ret = 1;
    while (p)
    {
        if (p & 1)
            ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x, mod - 2)

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> mp[i][j];
    i64 ans = 0;
    for (int j = 0; j < m; ++j)
    {
        std::vector<i64> p(n);
        for (int i = 0; i < n; ++i)
            p[i] = mp[i][j];
        std::sort(p.begin(), p.end());
        i64 res = 1;
        for (int i = 0; i < n; ++i)
            if (p[i] <= n)
            {
                res = res * (p[i] - i - 1) % mod * inv(n - i) % mod;
            }
        ans = ((ans + 1 - res) % mod + mod) % mod;
    }
    std::cout << ans;
    return 0;
}