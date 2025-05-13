#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
    这题要我们的操作就是算在每个地方放警察局然后算最多安全路径的地方

    1.先算0到n-1 每个点的最短距离，同时把0到n-1最短路径的条数
    dis1[],way1[]
    2.再算n-1到0 每个点的最短距离，同时把0到n-1最短路径的条数
    dis2[],way2[]
    3.l 为0到n-1到最短路径 sum为0到n-1的总共路的条数
    4.判断i=0到n-1 如果u，v其中有一条==i那就判断：dis2[v] + 1 == dis2[u]
    这个可以判断i是不是最短路上的点然后 sr += way1[u] * way2[v]就是这个点建一个警局之后会有几条安全路线出现。
*/
const ll N = 2e5;
vector<ll> e[N];
vector<ll> dis1(N + 1, 1e18), way1(N + 1, 0), dis2(N + 1, 1e18), way2(N + 1, 0);
ll n = 0, m = 0, k = 0;
void bfs1(ll st)
{
    queue<ll> q;
    dis1[st] = 0;
    way1[st] = 1;
    q.push(st);
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        for (auto u : e[v])
        {
            if (dis1[v] + 1 < dis1[u])
            {
                dis1[u] = dis1[v] + 1;
                way1[u] = way1[v];
                q.push(u);
            }
            else if (dis1[v] + 1 == dis1[u])
            {
                way1[u] += way1[v];
            }
        }
    }
}
void bfs2(ll st)
{
    queue<ll> q;
    dis2[st] = 0;
    way2[st] = 1;
    q.push(st); 
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        for (auto u : e[v])
        {
            if (dis2[v] + 1 < dis2[u])
            {
                dis2[u] = dis2[v] + 1;
                way2[u] = way2[v];
                q.push(u);
            }
            else if (dis2[v] + 1 == dis2[u])
            {
                way2[u] += way2[v];
            }
        }
    }
}

void solve()
{
    string s;
    cin >> n >> m;
    vector<ll> a(n);
    vector<pair<ll, ll>> edge;
    for (ll i = 0; i < m; i++)
    {
        ll u = 0, v = 0;
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
        edge.push_back({u, v});
    }
    bfs1(0);
    bfs2(n - 1);
    ll l = dis1[n - 1];
    ll sum = way1[n - 1];
    double ans = 0.0;
    for (ll i = 0; i < n; i++)
    {
        ll sr = 0;
        for (auto [u, v] : edge)
        {
            if ((u != i) && (v != i))
                continue;
            if (dis1[u] + 1 + dis2[v] == l)
            {
                sr += way1[u] * way2[v];
            }
            if (dis1[v] + 1 + dis2[u] == l)
            {
                sr += way1[v] * way2[u];
            }
        }
        double avg = (double)sr / sum;
        ans = max(ans, avg);
    }
    cout << fixed << setprecision(12) << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
}
