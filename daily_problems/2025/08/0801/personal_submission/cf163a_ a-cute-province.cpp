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
/*
    dp[i][j]定义以i-1结尾的s的子字符串可以和t的前j个字符的子序列相等的个数
*/
void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> dp(n+1);
    for(int j = 1; j <= m; j ++){
        for(int i = n; i >= 1; i --){
            if(s[i-1] == t[j-1])dp[i] = dp[i] + dp[i-1] + 1;

            dp[i]%=mod;
        }
       
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++)ans += dp[i], ans %=mod;
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
