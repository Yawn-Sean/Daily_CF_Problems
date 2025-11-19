#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 2e5 + 10;

void solve()
{   
   int n;
   cin >> n;
   vector<vector<int>> g(n+1);
   vector<int> p(n+1), vis(n+1), in(n+1);
   for(int i = 1; i <= n; i ++){
    for(int j = 1; j <= n; j ++){
        char x;
        cin >> x;
        if(x != '0')g[i].emplace_back(j);
    }
   }
   auto dfs = [&](auto &dfs, int u, int fa)->void{
    vis[u] = 1;
    p[u] = fa;
    in[fa] ++;
    for(auto v : g[u]){
        if(!vis[v]){
            dfs(dfs, v, u);
        }
    }
   };
   dfs(dfs, 1, 0);
   queue<int> q;
   int ok = 1;
   for(int i = 1; i <= n; i ++){
    if(in[i] == 0)q.push(i);
    if(vis[i] == 0)ok = 0;
   }
   if(ok){
    cout << "Yes\n";
    while(!q.empty()){
        auto s = q.front(); q.pop();
        if(p[s] > 0)cout << p[s] <<' ' << s << '\n';   
        if(--in[p[s]] == 0)q.push(p[s]);     
    }
    cout << '\n';
   }
   else {
    cout << "No\n";
   }
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //t = 1;
    cin >> t;    
    while (t--)
    {
        solve();
    }
    return 0;
}
