#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n, m;
using pt = std::pair<int, int>;

struct dsu
{
    std::vector<int> d, sz;
    dsu(int n)
    {
        d.resize(n);
        iota(d.begin(), d.end(), 0);
        sz.assign(n, 1);
    }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v)
    {
        if (get_root(u) != get_root(v))
        {
            sz[get_root(v)] += sz[get_root(u)];
            sz[get_root(u)] = 0;
            d[get_root(u)] = get_root(v);
            return true;
        }
        else
            return false;
    }
    int get_res(int cnt)
    {
        std::vector<int> res(cnt + 1, 0);
        for (int x : sz)
            for (int i = 0; i <= cnt; ++i)
                if (x > res[i])
                    std::swap(x, res[i]);
        return std::accumulate(res.begin(), res.end(), 0);
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    int u, v;
    dsu d(n);
    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> u >> v;
        u--, v--;
        cnt += !d.merge(u, v);
        std::cout << d.get_res(cnt) - 1 << '\n';
    }

    return 0;
}