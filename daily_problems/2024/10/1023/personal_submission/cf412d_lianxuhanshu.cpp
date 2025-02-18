#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 3e4 + 10, mod = 1e9 + 7;
int n, m, k;

vector<int> g[N];
bool vis[N];

void dfs(int u)
{
    for (auto &v : g[u])
    {
        if (vis[v])
            continue;
        vis[v] = true;
        dfs(v);
    }
    cout << u << ' ';
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            vis[i] = true;
            dfs(i);
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
