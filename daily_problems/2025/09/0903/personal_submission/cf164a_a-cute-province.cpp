#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e6+10; 
const int mod = 1e9 + 7;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> f(n+1), vis(n+1), dp1(n+1), dp2(n+1);
    vector<vector<int>> g1(n+1), g2(n+1);
    for(int i = 1; i  <=n; i++)cin >> f[i];
    for(int i = 1;  i <=m; i ++){
        int u, v;
        cin >> u >> v;
        g1[u].emplace_back(v);
        g2[v].emplace_back(u);
    }
    queue<int> q;
    for(int i = 1; i <=n; i++)if(f[i] == 1)q.push(i), dp1[i] = 1;
    while(!q.empty()){
        auto u = q.front();q.pop();
        for(auto v : g1[u]){
            dp1[v] = 1;
            if(!vis[v] && f[v] != 1){           
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    vis.assign(n+1, 0);
    for(int i = 1; i <=n; i++)if(f[i] == 2)q.push(i), dp2[i] = 1;
    while(!q.empty()){
        auto u = q.front();q.pop();
        for(auto v : g2[u]){
            dp2[v] = 1;
            if(!vis[v] && f[v] != 1){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    for(int i = 1; i <=n; i++){
        cout << (dp1[i] & dp2[i]) << '\n';
    }
}
signed cute_prov0nce()
{
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
