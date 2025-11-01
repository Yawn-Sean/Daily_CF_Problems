#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e5 + 3;
const int N = 3e5 + 10;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), p(n+1), dp(n+1);
    vector<vector<int>> g(n+1);
    for(int i = 1; i <= n; i ++)cin >> a[i];
    for(int i = 2; i <= n; i ++){
        cin >> p[i];
        g[p[i]].emplace_back(i);
    }
    int ans = 0;
    auto dfs = [&](auto &dfs, int u)->void{
        dp[u] = a[u];
        for(auto v : g[u]){
            dfs(dfs, v);
            ans = max(ans, dp[u] + dp[v] + 1);
            dp[u] = max(dp[u], dp[v]+1);
        }
        
    };
    dfs(dfs, 1);    
    cout << ans << '\n';
   
}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
