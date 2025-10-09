#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;
void f(int x, set<int> &v){
    while(x%2 == 0){
        v.insert(2);
        x/=2;
    }
    for(int i = 3; i * i <= x; i +=2){
        while(x%i == 0){
            v.insert(i);
            x/=i;
        }
    }
    if(x > 1)v.insert(x);
}
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i ++)cin >> p[i];
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    map<PII, int> dp;
    int ans = 0;
    auto dfs = [&](auto &dfs, int u, int fa)->void{
        for(auto v : g[u]){
            if(v != fa){
                dfs(dfs, v, u);               
            }
        }
        set<int> st;
        f(p[u], st);
        for(auto i : st){
            dp[(PII){u, i}] = 1;
            for(auto v : g[u]){     
                if(v != fa && dp.count({v, i})){                    
                    ans = max(ans, dp[(PII){u, i}] + dp[(PII){v, i}]);
                    dp[(PII){u, i}] = max(dp[(PII){u, i}], dp[(PII){v, i}] + 1);     
                }
            }
        }
        
    };
   
    dfs(dfs, 0, -1);
    if(ans > n/2)cout << "YES" << '\n';
    else cout << "NO" << '\n';

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
