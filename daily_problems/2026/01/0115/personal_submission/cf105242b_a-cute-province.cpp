#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9+7;
const int N = 1e7 + 10;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    vector<int> p(n+1), d(n+1);
    int rt = -1;
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        d[u] ++;
        d[v] ++;
    }
    vector<int> vis(n+1);
    for(int i = 1; i <= n; i ++){
        if(d[i] > 3){
            cout << "NO\n";
            return;
        }
        if(d[i] == 3)rt = i, vis[i] = 1;
    }
    if(rt == -1){
        cout << "YES\n";
        return ;
    }
    auto dfs = [&](auto &&dfs, int u, int fa)->void{
        p[u] = fa;
        for(auto v : g[u]){
            if(v != fa)dfs(dfs, v, u);
        }
    };
    dfs(dfs, rt, 0);
    for(int i = 1; i <= n; i ++){
        if(vis[i]){
            int cur = i;
            while(!vis[p[cur]])cur = p[cur], vis[cur] = 1;
        }
    }
    for(int i = 1; i <= n; i ++){
        if(!vis[i])continue;
        int sum = 0;
        for(auto u : g[i])sum += vis[u];
        if(sum > 2){
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
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
