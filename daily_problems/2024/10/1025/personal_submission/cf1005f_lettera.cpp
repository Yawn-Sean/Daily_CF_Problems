#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
int n, m, k, cnt, tot = 1;
const int N = 2E5 + 5;
vector<vector<pair<int, int>>> g;
vector<vector<int>> c;
int vis[N];
void bfs()
{
    queue<int> q;
    q.push(1);
    vector<int> dis(n + 1, (int)1E9);
    dis[1] = 1;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (auto [v, id] : g[u])
        {
            if (dis[v] >= dis[u] + 1)
            {
                if (dis[v] > dis[u] + 1)
                {
                    q.push(v);
                }
                dis[v] = dis[u] + 1;
                c[v].push_back(id);
            }
        }
    }
}
void dfs(int x)
{
    if (cnt == tot)
    {
        return;
    }
    if (x == n + 1)
    {
        cnt++;
        for (int i = 1; i <= m; i++)
        {
            cout << vis[i];
        }
        cout << "\n";
    }
    else
    {
        for (auto i : c[x])
        {
        	
            vis[i] = 1;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}
void solve()
{

    cin >> n >> m >> k;
    g.resize(n + 1);
    c.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    bfs();
    for (int i = 2; i <= n; i++)
    {
        if (1ll * tot * c[i].size() > k)
        {
            tot = k;
            break;
        }
        else
        {
            tot *= c[i].size();
        }
    }
    cout << tot << "\n";
    dfs(2);
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
