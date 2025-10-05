#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10;
const int mod = 1e9 + 7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(k+1);
    for(int i = 1; i <= k; i ++)cin >> x[i];
    vector<vector<PII>> g(n+1);
    for(int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v,1);
        g[v].emplace_back(u,1);
    }
    vector<PII> ans;

    for(int i = 1; i <= k; i ++){
      
        
        if(i == 1){
            if(x[i] != 1){
                ans.emplace_back(x[i], 1);
                g[x[i]].emplace_back(1,1);
                g[1].emplace_back(x[i], 1);
            }
        }
        else{
            ans.emplace_back(x[i-1], x[i]);
            g[x[i]].emplace_back(x[i-1],1);
            g[x[i-1]].emplace_back(x[i], 1);
        }
        

    }
    vector<int> dis(n+1, 1e18), vis(n+1);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0 ,1});
    dis[1] = 0;
    while(!pq.empty()){
        auto [_, u] = pq.top(); pq.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(auto [v, w] : g[u]){
            if(!vis[v] && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    int up = -1;
    for(int i = 1; i <= k; i ++){
        if(up +1 > dis[x[i]]){
            cout << -1 << '\n';
            return ;
        }
        up = dis[x[i]];
    }
    cout << ans.size() << '\n';
    for(auto [u, v] : ans)cout << u << ' ' << v << '\n';


}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
