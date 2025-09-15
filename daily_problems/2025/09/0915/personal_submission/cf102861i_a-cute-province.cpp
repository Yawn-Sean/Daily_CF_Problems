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
int qpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1)res = res * a %mod;
        b >>= 1;;
        a = a * a %mod;
    }
    return res;
}
int inv(int x){
    return qpow(x, mod-2);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    vector<vector<int>> g(n+1);
    vector<array<int, 2>> dp(n+1, array<int, 2>{0, 0});
    for(int i = 1; i < n; i++)cin >> p[i];
    for(int i = 1 ; i < n; i++)g[p[i]].emplace_back(i+1);
    auto dfs= [&](auto &&dfs, int u, int fa) ->void{
        if(g[u].size() ==0){
            dp[u][1] = 1;
            return;
        }
        int sum1 = 1, pre = 1;
        vector<int> ve, sub, ve2;
        for(auto v : g[u]){
            if(v != fa){
                dfs(dfs, v, u);
                sum1 *= (dp[v][0] + dp[v][1])%mod;
                sum1 %= mod;
                ve.emplace_back((dp[v][0] + dp[v][1])%mod);
                ve2.emplace_back(dp[v][1]);
            }
        }
        int m = ve.size();
        sub.resize(m+1);
        sub[m] = 1;
        for(int i = m-1; i >= 0; i --){
            sub[i] = sub[i+1] * ve[i]%mod;
        }
        for(int i = 0 ;i < m; i++){
            dp[u][1] += pre * ve2[i]%mod * sub[i+1]%mod;
            dp[u][1] %= mod;
            pre *= ve[i];
            pre %=mod; 
        }
        dp[u][0] = sum1;
    };
    dfs(dfs, 1, 0);
    cout <<(dp[1][1] + dp[1][0])%mod<<'\n';



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
