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
const int N = 1e6 + 10;
int dp[N], s[N];
void solve()
{
    int k;
    cin >> k;
    dp[1] = 1;
    s[1] = 1;
    for(int i = 2; i <= k; i ++){
        dp[i] = s[i-1] - s[(i+1)/2-1];
        dp[i] %= mod;
        if(dp[i] < 0)dp[i] += mod;
        s[i] = s[i-1] + dp[i];
        s[i] %= mod;
    }
    cout << dp[k] << '\n';
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
