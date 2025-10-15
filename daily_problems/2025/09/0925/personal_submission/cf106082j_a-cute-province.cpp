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
/*
    prim可以在稠密图时n^2
*/
void solve()
{
    int n;
    cin >> n;
    vector<PII> point(n+1);
    vector<vector<int>> ans(n+1, vector<int> (n+1)), dis(n+1, vector<int> (n+1));
    for(int i = 1; i <= n ; i ++){
        int x, y;
        cin >> x >> y;
        point[i] = {x, y};
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            dis[i][j] = (point[i].x - point[j].x) * (point[i].x - point[j].x) + (point[i].y - point[j].y) * (point[i].y - point[j].y);
        }
    }   
    vector<int> key(n+1, 1e18), vis(n+1), parent(n+1), v(n+1);
    vector<vector<int>> e(n+1);
    key[1] = 0;
    vis[1] = 1;
    for(int i = 1; i <=n; i++){
        if(!vis[i] && dis[1][i] < key[i]){
            key[i] = dis[1][i];
            parent[i] = 1;
        }
    }
    
    for(int count = 1; count <= n-1; count++){
        int mi = 1e18, idx;
        for(int i = 1 ; i<= n; i++){
            if(!vis[i] && mi > key[i]){
                mi = key[i];
                idx = i;
            }
        }
        
        vis[idx] = 1;
        e[idx].emplace_back(parent[idx]);
        e[parent[idx]].emplace_back(idx);
        for(int i = 1; i <=n; i++){
            if(!vis[i] && dis[idx][i] < key[i]){
                parent[i] = idx;
                key[i] = dis[idx][i];
            }
        }
        
    }
    auto dfs = [&](auto & dfs, int x, int y, int now)->void{
        ans[x][y] = now;
        v[y] = 1;
        for(auto u : e[y]){
            if(!v[u])dfs(dfs, x, u, max(now, dis[y][u]));
        }
        return;
    };
    for(int st = 1; st <= n; st ++){
        v.assign(n+1, 0);
        dfs(dfs, st, st, 0);
    }
    
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        
        cout <<fixed << setprecision(6)<< sqrt(ans[u][v]) << '\n';
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
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
