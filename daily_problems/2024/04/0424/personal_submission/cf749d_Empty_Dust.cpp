#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int id[MAXN], sz[MAXN], nxt_id[MAXN], nxt_bid[MAXN], n, q, k;
using pt = std::pair<int, int>;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> id[i] >> sz[i];

    std::map<int, int> mp, mp2;
    int _suf = n;
    for (int i = n; i; --i)
    {
        if (!mp.count(id[i]))
        {
            nxt_id[_suf] = i;
            mp[id[i]] = i;
            _suf = i;
            for (auto &[num, pos] : mp2)
            {
                nxt_bid[mp[num]] = pos;
                mp[num] = pos;
            }
            mp2.clear();
        }
        else
            mp2[id[i]] = i;
    }
    nxt_id[_suf] = -1;
    for (auto &[num, pos] : mp2)
    {
        nxt_bid[mp[num]] = pos;
        mp[num] = pos;
    }
    for (auto &[num, pos] : mp)
        nxt_bid[pos] = -1;

    std::cin >> q;
    while (q--)
    {
        std::cin >> k;
        std::set<int> query;
        for (int i = 1, num; i <= k; ++i)
            std::cin >> num, query.insert(num);
        int x = n;
        while (~x && query.count(id[x]))
            x = nxt_id[x];
        if (x == -1)
        {
            std::cout << "0 0\n";
            continue;
        }
        int lim = nxt_id[x];
        while (~lim && query.count(id[lim]))
            lim = nxt_id[lim];
        while (~nxt_bid[x] && nxt_bid[x] > lim)
            x = nxt_bid[x];
        std::cout << id[x] << ' ' << sz[x] << '\n';
    }
    return 0;
}