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
#define int long long

const int inf = 1000000005;
const int N = 3005;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
    {
        g[i][i] = 0;
    }
    vector<vector<int>> edge(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u].pb(v);
    }

    for (int i = 0; i < n; i++)
    {
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : edge[u])
            {
                if (g[i][v] > g[i][u] + 1)
                {
                    g[i][v] = g[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    vector<vector<int>> from(n, vector<int>(3, -1)), to(n, vector<int>(3, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || g[j][i] == inf)
                continue;
            int cur = j;
            for (int k = 0; k < 3; k++)
            {
                if (from[i][k] == -1 || g[from[i][k]][i] < g[cur][i])
                {
                    swap(cur, from[i][k]);
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (i == j || g[i][j] == inf)
                continue;
            int cur = j;
            for (int k = 0; k < 3; k++)
            {
                if (to[i][k] == -1 || g[i][to[i][k]] < g[i][cur])
                {
                    swap(cur, to[i][k]);
                }
            }
        }
    }

    int ans = 0;
    vector<int> anst;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j || g[i][j] == inf)
                continue;
            for (int k = 0; k < 3; k++)
            {
                int u = from[i][k];
                if (u == -1 || u == j)
                    continue;
                for (int kk = 0; kk < 3; kk++)
                {
                    int v = to[j][kk];
                    if (v == -1 || v == i || v == u)
                        continue;
                    int d = g[u][i] + g[i][j] + g[j][v];
                    if (d > ans)
                    {
                        ans = d;
                        anst = {u, i, j, v};
                    }
                }
            }
        }

    for (int i = 0; i < 4; i++)
    {
        cout << anst[i] + 1 >> (i == 3 ? "\n" : " ");
    }
    return 0;
}
