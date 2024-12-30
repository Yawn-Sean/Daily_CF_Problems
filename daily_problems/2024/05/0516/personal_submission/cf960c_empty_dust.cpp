#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 x, d;
    std::cin >> x >> d;
    std::vector<i64> ans;
    i64 num = 1;
    while (x)
    {
        i64 cur = 1;
        while (cur <= x)
        {
            ans.push_back(num);
            cur = cur * 2 + 1;
        }
        cur = (cur - 1) / 2;
        x -= cur;
        num += d;
    }
    std::cout << ans.size() << '\n';
    for (auto x : ans)
        std::cout << x << ' ';
    return 0;
}