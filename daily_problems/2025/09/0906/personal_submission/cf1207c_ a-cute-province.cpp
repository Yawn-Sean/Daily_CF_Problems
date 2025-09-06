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
void solve()
{
    int n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<array<int, 2>> dp(n, {(int)1e18, (int)1e18});
    dp[0][0] = b;
    for(int i = 1 ;i < n; i ++){
        if(s[i-1] == '0'){
            dp[i][0] = min(dp[i-1][0] + a + b, dp[i-1][1] + 2 * a + b);
            dp[i][1] = min(dp[i-1][0] + 2 * a + 2 * b, dp[i-1][1] + a + 2 * b);
        }
        else{
            dp[i][1] = dp[i-1][1] + a + 2 * b;
        }
        //cout << dp[i][0] <<' ' << dp[i][1] << '\n';
    }
    cout << min(dp[n-1][1] + 2 * a + b, dp[n-1][0] + a + b) << '\n';
    
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t;
    cin >> t;
     //t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
