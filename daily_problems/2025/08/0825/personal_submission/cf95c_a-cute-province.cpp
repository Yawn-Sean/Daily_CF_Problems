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
    int n,m,x,y;
    cin >> n >> m>>x>>y;
    vector<vector<PII>> g(n+1);
    vector<int> vis2(n+1), t(n+1), c(n+1);
    for(int i = 1; i <= m; i++){
        int u,v, w;
        cin >> u >>v>>w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for(int i = 1; i <= n; i++){     
        cin >> t[i] >> c[i];
    }
    vector<int> dist2(n+1, 1e18);
    
    priority_queue<PII, vector<PII>, greater<PII>> pq2;
    pq2.push({0, x});
    dist2[x] = 0;
    while(!pq2.empty()){
        auto [_, s] = pq2.top();pq2.pop();
        if(vis2[s])continue;
        vis2[s] = 1;
        vector<int> vis1(n+1), dist1(n+1, 1e18);
        priority_queue<PII, vector<PII>, greater<PII>> pq1;
        pq1.push({0, s});
        dist1[s] = 0;
        while(!pq1.empty()){
            auto [_, u] = pq1.top();pq1.pop();
            if(vis1[u])continue;
            vis1[u] = 1;
            for(auto [v,w] : g[u]){
                if(!vis1[v] && dist1[v] > dist1[u] + w){
                    dist1[v] = dist1[u] + w;
                    pq1.push({dist1[v], v});
                }
            }
        }
        for(int i = 1; i <=n; i++){
            if(i!= s && dist1[i] <= t[s]){
                if(!vis2[i] && dist2[i] > dist2[s] + c[s]){
                    dist2[i] = dist2[s] + c[s];
                    pq2.push({dist2[i], i});
                }
            }
        }
    }
    if(dist2[y] != 1e18)cout << dist2[y] << '\n';
    else cout << -1 << '\n';
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
