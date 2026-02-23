#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 4e5 + 10;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> g(n+1);
    for(int i = 1; i <= m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].emplace_back(v, c);
    }
    vector<PII> vis(n+1, {-1, -1});
    vector<int> ans(n+1);
    auto dfs = [&](auto &&dfs, int u)->void{
        ans[u] = 1;
        auto [c1, c2] = vis[u];
        for(auto [v, c] : g[u]){
            if(c == vis[v].x || c == vis[v].y)continue;
        	if(vis[v].y != -1)continue;
            if(c1 != -1 && c1 != c){
                if(vis[v].x == -1)vis[v].x = c;
                else vis[v].y = c;
                dfs(dfs, v);
            }
            else if(c2 != -1 && c2 != c){
                if(vis[v].x == -1)vis[v].x = c;
                else vis[v].y = c;
                dfs(dfs, v);
            }
        }
    };
    vis[1] = {0, 0};
    dfs(dfs, 1);
    for(int i = 1; i <= n; i ++){
        if(ans[i])cout << i <<' ';
    }
    cout << '\n';
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
