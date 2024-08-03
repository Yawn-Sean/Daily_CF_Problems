#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    std::vector<int> f(n + 1), g(n + 1), h;
    for (int i = 1; i <= n; ++i)
        std::cin >> f[i];
    bool flag = true;
    std::map<int, int> mp;
    for (int i = 1, j = 1; i <= n; ++i)
    {
        if (f[f[i]] != f[i])
        {
            std::cout << -1;
            return 0;
        }
        if (!mp.count(f[i]))
        {
            h.push_back(f[i]);
            mp[f[i]] = j++;
        }
        g[i] = mp[f[i]];
    }
    std::cout << h.size() << '\n';
    for (int i = 1; i <= n; ++i)
        std::cout << g[i] << ' ';
    std::cout << '\n';
    for (int &x : h)
        std::cout << x << ' ';
    return 0;
}