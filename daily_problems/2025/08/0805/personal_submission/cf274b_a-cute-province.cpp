#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10; 
const int mod = 998244353;
void solve()
{
    int n; cin >> n;
    vector<int> a(n+1), v(n+1), f(n+1), g(n+1);
    vector<vector<int>> path(n+1);
    for(int i =1 ; i < n;i ++){
        int u, v;
        cin >> u>> v;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }
    for(int i =1 ; i <= n;i ++)cin >> a[i];
    int ans = 0;
    auto dfs = [&](auto &dfs, int u, int fa) ->void{

        for(auto v : path[u]){
            if(v != fa){
                dfs(dfs, v, u);
                f[u] = max(f[u], f[v]);
                g[u] = max(g[u], g[v]);
            }
        }
        if(a[u] + f[u] -g[u] >= 0)g[u] += a[u] + f[u] -g[u];
        else f[u] += abs(a[u] + f[u] -g[u]);
    };
    dfs(dfs, 1, 0);
    cout << f[1] + g[1] << '\n';
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
