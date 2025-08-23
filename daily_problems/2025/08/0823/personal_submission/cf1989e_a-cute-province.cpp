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
const int mod = 998244353;
/*  
    dpi,j 前i个分成j块的个数, 当j==k时定义为至少k块的个数
    dp[i][k] = S(sum[i][j]) (j>=k);
    dp[i][j] = sum[i][j] (j<k);
*/
void solve()
{
    int n,k;
    cin >> n>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    vector<int> sum(k+1);
    dp[0][0]=1;
    sum[0] = 1;
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= k; j ++){
            dp[i][j] = sum[j-1];
            if(j == k)dp[i][j] += sum[j];
            if(i>2 && i < n) {
                dp[i][j] = dp[i][j] - dp[i-2][j-1];
                if(j == k)  dp[i][j] =dp[i][j] - dp[i-2][j];
            }
            dp[i][j] = (dp[i][j] + mod)%mod;
        }
     
        for(int j = 0; j <= k;j ++){
            sum[j] += dp[i][j];
            sum[j]%=mod;
        }
        
        
    }
    cout << dp[n][k] << '\n';
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
