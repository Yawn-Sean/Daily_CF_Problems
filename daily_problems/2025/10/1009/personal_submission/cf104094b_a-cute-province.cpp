#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;
void solve() {
    int n ,m;
    cin >> n >> m;
    int s, t, L;
    cin >> s >> t>> L;
    s--;
    t--;
    vector<vector<PII>> g(n);
    vector<int> dp1(n), dp2(n), dis1(n, 1e18),  dis2(n, 1e18), vis(n);
    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    dis2[t] = 0;
    dp2[t] = 1;
    pq.push({0, t});

    while(!pq.empty()){
        auto [_, u] = pq.top(); pq.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(auto [v, w] : g[u]){
            if(!vis[v] && dis2[v] > dis2[u] + w){
                dis2[v] = dis2[u] + w;
                dp2[v] = dp2[u];
                pq.push({dis2[v], v});
            }
            else if(dis2[v] == dis2[u] + w){
                dp2[v] += dp2[u];
                dp2[v] %= mod;

            }
        }
    }
    vis.assign(n, 0);

    int ans = 0;
    if (dis2[s] == L)ans = dp2[s];
    dis1[s] = 0;
    dp1[s] = 1;
    pq.push({0, s});
    while(!pq.empty()){
        auto [_, u] = pq.top(); pq.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(auto [v, w] : g[u]){
            if(dis1[u] + dis2[u] == dis2[s] && u != t &&dis1[u] + dis2[v] + w == L && dis2[v] + w > dis2[u]) {
                ans += dp1[u] * dp2[v] %mod, ans %= mod;
            }
            if(!vis[v] && dis1[v] > dis1[u] + w){

                dis1[v] = dis1[u] + w;
                dp1[v] = dp1[u];
                pq.push({dis1[v], v});
            }
            else if(dis1[v] == dis1[u] + w){
                dp1[v] += dp1[u];
                dp1[v] %= mod;
            }
        }
    }


    cout << ans << '\n';
}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
