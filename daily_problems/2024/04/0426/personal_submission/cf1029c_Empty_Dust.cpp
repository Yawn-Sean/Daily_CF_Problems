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
    int maxl = -1, maxl2 = -1, minr = 1e9, minr2 = 1e9;
    int maxl_pos = -1, minr_pos = -1;
    for (int i = 1; i <= n; ++i)
    {
        int l, r;
        std::cin >> l >> r;
        if (maxl <= l)
        {
            maxl2 = maxl;
            maxl = l;
            maxl_pos = i;
        }
        else if (maxl2 <= l)
            maxl2 = l;
        if (minr >= r)
        {
            minr2 = minr;
            minr = r;
            minr_pos = i;
        }
        else if (minr2 >= r)
            minr2 = r;
    }
    if (maxl_pos == minr_pos)
    {
        std::cout << std::max(0, minr2 - maxl2);
        return 0;
    }
    std::cout << std::max({0, minr - maxl2, minr2 - maxl});
    return 0;
}