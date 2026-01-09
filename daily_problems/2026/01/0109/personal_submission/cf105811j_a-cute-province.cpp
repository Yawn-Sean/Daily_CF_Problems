#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
void solve()
{
   int n, m;
   cin >> n >> m;
   vector<vector<PII>> g1(n+1), g2(n+1);
   for(int i = 1; i <= m; i ++){
    int u, v, w;
    cin >> u >> v >> w;
    g1[u].emplace_back(v, w);
    g2[v].emplace_back(u, w);
   }
   auto dij = [&](vector<vector<PII>> & g)->auto{
    vector<int> d(n+1, 1e18), vis(n+1);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [s, u] = pq.top();pq.pop(); 
        if(vis[u])continue;
        d[u] = s;
        vis[u] = 1;
        for(auto [v, w] : g[u]){
            if(d[v] >= max(w, d[u])){
                pq.push({max(w, d[u]), v });
            }
        }
    }
    return d;
   };
   vector<int> d1 = dij(g1), d2 = dij(g2);
   for(int i =1 ; i <= n; i ++){
    //cout << d1[i] <<' ' << d2[i] << '\n';
    if(d1[i] < d2[i]){
        cout << "NO\n";
        return ;
    }
   }
   cout << "YES\n";
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
