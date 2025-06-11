#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (deg[i] > 4)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    int len = 1 << 29;
    pair<int, int> dirs[4]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<pair<int, int>> pos(n);
    auto dfs = [&](auto self, int u, int fa, int dir) -> void {
        int curdir = 0;
        len >>= 1;
        for (auto v : g[u])
        {
            if (v != fa)
            {
                if (curdir == dir)
                {
                    curdir++;
                }
                //cerr<<u+1<<" "<<v+1<<" "<<dir<<" "<<curdir<<"\n";
                auto &[x1, y1] = pos[u];
                auto &[x2, y2] = pos[v];
                auto &[dx, dy] = dirs[curdir];
                x2 = x1 + dx * len;
                y2 = y1 + dy * len;   
                //  cerr<<u+1<<" "<<v+1<<" "<<(curdir^2)<<" C\n";
                self(self, v, u, curdir ^ 2);
                curdir++;
            }
        }
         
    };
    dfs(dfs, 0, -1, 5);
    for (auto [x, y] : pos)
    {
        cout << x << " " << y << "\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
