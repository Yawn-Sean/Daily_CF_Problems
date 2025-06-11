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

const int N = 3e5 + 5;
int ans = 0;
vector<pii> adj[N];
vector<int> dist(N, 0);
vector<bool> rem(N, false);
vector<int> val(N);
void dfs(int src, int pr)
{
    dist[src] = max(dist[src], i64(0));
    if (dist[src] > val[src] || (pr != -1 && rem[pr]))
    {
        rem[src] = true;
        ans++;
    }

    for (int i = 0; i < adj[src].size(); i++)
    {
        int v = adj[src][i].first;
        int w = adj[src][i].se;
        if (v == pr)
        {
            continue;
        }
        dist[v] = dist[src] + w;
        dfs(v, src);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 1; i < n; i++)
    {
        int v, w;
        cin >> v >> w;
        v--;
        adj[i].pb(mp(v, w));
        adj[v].pb(mp(i, w));
    }

    dfs(0, -1);
    cout << ans;
    return 0;
}
