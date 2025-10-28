#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 2e3 + 10;

void solve()
{   
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> m(n+1), t(n+1);
    for(int i = 1; i <=n; i ++)cin >> m[i] >> t[i];
    map<int, int> mp1, mp2;
    int ans = 0;
    auto dfs1 = [&](auto &&dfs1, int now, int val)->void{
        if(now == n/2+1){
            mp1[val] ++;
            return;
        }
        dfs1(dfs1, now+1, val);
        dfs1(dfs1, now+1, val + b * m[now] - a * t[now]);
    };
    auto dfs2 = [&](auto &&dfs2, int now, int val)->void{
        if(now == n+1) {
            mp2[val] ++;
            return;
        }
        dfs2(dfs2, now+1, val);
        dfs2(dfs2, now+1, val + b * m[now] - a * t[now]);
    };
    dfs1(dfs1, 1, 0);
    dfs2(dfs2, n/2+1, 0);
    for(auto [u, v] : mp1){
        if(mp2.count(-u))ans += mp2[-u] * v; 
    }
    cout << ans-1 << '\n';
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
