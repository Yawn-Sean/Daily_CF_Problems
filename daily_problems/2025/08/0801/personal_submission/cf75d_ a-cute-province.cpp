#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10; 
const int mod = 1e9 + 7;

void solve()
{
     int n, m;
     cin >> n>> m;
     vector<vector<int>> v(n);
     for(int i = 0;i < n;i++){
        int l;
        cin >> l;
        v[i].resize(l);
        for(auto &x : v[i])cin >> x;
     }
     vector<int> V(m), mal(n, -1e9), mar(n, -1e9), all(n), dp(m), vis(n+1);
     for(auto &x : V)cin >> x, x--, vis[x] = 1;
     int ans = -1e9;
     for(int i = 0; i < n; i++){
        int len = 0;
        if(vis[i])
        for(auto &a : v[i]){
            len = max(len + a, a);
            ans = max(ans, len);
        }   
        int sum = 0;
        for(auto &a : v[i])sum += a, mal[i] = max(mal[i], sum), all[i] += a;;
        sum = 0;
        for(int j = v[i].size()-1; j >= 0; j --)sum += v[i][j], mar[i] = max(mar[i], sum);
     }
     dp[0] = mar[V[0]];
     for(int i = 1; i < m; i ++){
        dp[i] = max(dp[i-1] + all[V[i]], mar[V[i]]);
     }
     ans = max(ans, max(mal[V[0]], dp[m-1]));
     for(int i = 0; i < m-1; i ++){
        ans = max(ans, dp[i] + mal[V[i+1]]);
     }
     cout << ans << '\n';
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
