#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;

void solve()
{
    int n, m;
    cin >> n >> m;
    int st, en;
    cin >> st >> en;
    vector<vector<int>> dis(n + 2, vector<int>(n + 2, 1e18));
    vector<PII> e[n + 1], ne[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // dis[v][u]=dis[u][v]=min(dis[u][v],w);
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    vector<PII> info(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        info[i] = {a, b};
    }

    for (int i = 1; i <= n; i++)
    {

        vector<int> vis(n + 1, 0);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({0, i});
        dis[i][i] = 0;
        while (!pq.empty())
        {
            auto [x, y] = pq.top();
            pq.pop();
            if (vis[y])
                continue;
            vis[y] = true;
            for (auto [v, w] : e[y])
            {
                if (dis[i][v] > dis[i][y] + w)
                {
                    dis[i][v] = dis[i][y] + w;
                    pq.push({dis[i][v], v});
                }
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] <= info[i].first)
            {
                ne[i].push_back({j, info[i].second});
            }
        }
    }
    vector<int> vis(n + 1, 0), dist(n + 1, 1e18);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, st});
    dist[st] = 0;
    while (!pq.empty())
    {
        auto [x, y] = pq.top();
        pq.pop();
        if (vis[y])
            continue;
        vis[y] = true;
        for (auto [v, w] : ne[y])
        {
            if (dist[v] > dist[y] + w)
            {
                dist[v] = dist[y] + w;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[en] >= 1e17)
    {
        cout << -1 << endl;
        return;
    }
    cout << dist[en] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;

    // cin >> T;
    while (T--)
        solve();
    return 0;
}
