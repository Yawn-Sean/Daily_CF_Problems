#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e4 + 10;

void solve()
{
    int n, m, T;
    cin >> n >> m >> T;
    vector<vector<pair<int, double>>> g(n);
    for(int i = 1; i <= m; i ++){
        int u, v, l, c;
        cin >> u >> v >> l >> c;
        u--;
        v--;
        g[u].emplace_back(v, sqrtl(l*c));
        g[v].emplace_back(u, sqrtl(l*c));
    }
    vector<double> dis(n, 1e18);
    vector<int> vis(n);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, 0});
    dis[0] = 0;
    while(!pq.empty()){
        auto [_, u] = pq.top(); pq.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(auto [v, w] : g[u]){
            if(!vis[v] && dis[u] + w <= dis[v]){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
   
    cout <<fixed << setprecision(6) << dis[n-1] * dis[n-1]/ T << '\n';

}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
