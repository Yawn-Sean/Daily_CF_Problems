#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 2e6 + 10;
int dp[N], inv[N+10];
void solve()
{   
   int l, r;
   cin >> l >> r;
   int len = r - l + 1;
    cout << dp[len] * (l+r)%mod*(mod+1)/2%mod << '\n';

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
    dp[1] = 1;
    int sum1 = 1, sum2 = 1;
    inv[1] = 1;
    for(int i = 2; i< N+10;  i++)inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 2; i < N ; i ++){
        dp[i] = 1 + inv[i-1] * 2 %mod * inv[i+2]%mod* ((i+1)*sum1%mod -sum2 + mod)%mod;
        dp[i]%=mod;
        sum1 += dp[i];
        sum1 %=mod;
        sum2 += i*dp[i]%mod;
        sum2 %=mod;
    }
    cin >> t;    
    while (t--)
    {
        solve();
    }
    return 0;
}
