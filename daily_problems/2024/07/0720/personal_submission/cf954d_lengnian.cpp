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

const int N = 1010;
int a[N], b[N];
int ds[N], dt[N];
vector<int> adj[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        a[i] = x, b[i] = y;
    }

    for (int i = 1; i <= n; i++)
    {
        ds[i] = dt[i] = 1e9;
    }
    ds[s] = dt[t] = 0;

    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ds[a[j]] > ds[b[j]] + 1)
                ds[a[j]] = ds[b[j]] + 1;
            if (ds[b[j]] > ds[a[j]] + 1)
                ds[b[j]] = ds[a[j]] + 1;
            if (dt[a[j]] > dt[b[j]] + 1)
                dt[a[j]] = dt[b[j]] + 1;
            if (dt[b[j]] > dt[a[j]] + 1)
                dist[b[j]] = dt[a[j]] + 1;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (min(ds[i] + 1 + dt[j], dt[i] + 1 + ds[j]) >= ds[t])
                res++;
        }
    }

    cout << res - m;
    return 0;
}
