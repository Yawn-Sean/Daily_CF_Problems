#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 3e5+10; 
const int mod = 1e9 + 7;
/*
    毛毛虫树
    什么是毛毛虫树？
    一棵毛毛虫树，是指存在一条主干路径,使得树上的所有节点到这条主干路径的距离都不超过1。
    换句话说，树上的所有节点，要么在主干路径上，要么直接与主干路径上的某个节点相连（就像毛毛虫的“腿”一样）。
    相当于求最长的带权直径(degree(v) - 1)之和最大。
*/
void solve()
{
   int n;
   cin >> n;
   vector<vector<int>> g(n+1);
   for(int i = 1; i < n; i ++){
    int x, y;
    cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
   }
   int ans = 0;
   vector<int> dp(n+1);
   auto dfs = [&](auto &dfs, int u, int fa)->void{
        for(auto v : g[u]){
            if(v!=fa){
                dfs(dfs, v, u);
                ans = max(ans, dp[u] + dp[v]);  
                dp[u] = max(dp[u], dp[v] + (int)g[u].size()-1);

            }
        }
   };
    dfs(dfs, 1, 0); 
    
    cout << ans+2 << '\n';
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     
     int t;
     cin >> t;
     //t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
