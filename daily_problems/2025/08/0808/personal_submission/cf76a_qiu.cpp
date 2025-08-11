#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = -1e18;
typedef pair<int, int> PII;
const int mod = 1e9 + 7, N = 2 * 1e6 + 10;
class DSU
{
    std::vector<int> f, sz;

public:
    DSU(int n)
    {
        f.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i)
            f[i] = i;
    }

    int find(int x)
    {
        if (f[x] != x)
            f[x] = find(f[x]);
        return f[x];
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            std::swap(x, y);
        f[y] = x;
        sz[x] += sz[y];
        return true;
    }

    int size(int x)
    {
        return sz[find(x)];
    }
};
struct node
{
    int u, v, g, s;
};

void solve()
{
    int n, m, gg, ss;
    cin >> n >> m >> gg >> ss;
    vector<node> e(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, g, s;
        cin >> u >> v >> g >> s;
        e[i] = {u, v, g, s};
    }
    sort(e.begin(), e.end(), [&](const node &x, const node &y)
         {
        if(x.g!=y.g) return x.g<y.g;
        else return x.s<y.s; });
    vector<int> a;
    int ans = 2 * 1e18;
    for (int i = 0; i < m; i++)
    {
        a.push_back(i);
        sort(a.begin(), a.end(), [&](const int &x, const int &y)
             { return e[x].s < e[y].s; });
        DSU dsu(n + 1);
        vector<int> b;
        int maxnums = 0;
        for (auto j : a)
        {
            auto [u, v, g, s] = e[j];
            if (dsu.same(u, v))
                continue;
            else
            {
                maxnums = max(maxnums, s);
                b.push_back(j);
                dsu.merge(u, v);
            }
        }
        if (dsu.size(1) == n)
        {
            ans = min(ans, gg * e[i].g + maxnums * ss);
        }
        a = b;
    }
    if (ans == 2 * 1e18)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}