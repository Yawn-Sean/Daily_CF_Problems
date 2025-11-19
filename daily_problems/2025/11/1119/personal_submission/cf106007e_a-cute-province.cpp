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
   int n, q;
   cin >> n >> q;
   vector<int> col(n+1, 1), p(n+1), ve;
   vector<vector<int>> g(n+1);
   int w = n, b = 0;
   for(int i = 1; i <= n; i ++){
     char x;
     cin >> x;
     if(x == '0') ve.emplace_back(i);
   }
   for(int i = 1; i < n; i ++){
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
   }
   
   auto dfs = [&](auto &dfs, int u, int fa)->void{
    p[u] = fa;
    for(auto v : g[u]){
        if(v != fa){
            dfs(dfs, v, u);
        }
    }
   };
   for(int i = 1; i <= q; i ++){
    int x;
    cin >> x;
    if(i == 1){
        w--;
        col[x] = 0;
        dfs(dfs, x, 0);
        for(auto st : ve){
            if(col[st] == 0)continue;
            if(col[st] == 1)w--;
            else b--;
            col[st] = 0;
            st = p[st];
            while(col[st] == 1)b ++,w--,col[st] = 2, st = p[st];
        }
    }
    else if(col[x] != 0){
        if(col[x] == 1)w--;
        else b--;
        col[x] = 0;
        x = p[x];
        while(col[x] == 1)b ++,w--,col[x] = 2, x = p[x];
    }
    cout << w * (w+1)/2 + w * b << '\n';
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
