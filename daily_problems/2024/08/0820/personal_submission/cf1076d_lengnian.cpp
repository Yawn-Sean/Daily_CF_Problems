#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
// #define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solve = [&]()
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<tuple<int, int, int>>> g(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            g[u].emplace_back(v, w, i);
            g[v].emplace_back(u, w, i);
        }

        vector<i64> dis(n, 1e18);
        dis[0] = 0;
        set<pair<i64, int>> h;
        h.emplace(0, 0);

        vector<int> p(n, -1);
        vector<int> ans;

        for (int ite = 0; ite < min(k + 1, n); ite++)
        {
            auto [d, u] = *h.begin();
            h.erase(h.begin());
            if (u != 0)
            {
                ans.pb(p[u]);
            }
            for (auto [v, w, i] : g[u])
            {
                if (i64 nd = dis[u] + w; nd < dis[v])
                {
                    h.erase(mp(dis[v], v));
                    dis[v] = nd;
                    p[v] = i;
                    h.emplace(dis[v], v);
                }
            }
        }

        cout << int(ans.size()) << '\n';
        for (int i = 0; i < int(ans.size()); i++)
        {
            if (i > 0)
            {
                cout << ' ';
            }
            cout << ans[i] + 1;
        }
        cout << '\n';
    };

    solve();

    return 0;
}
