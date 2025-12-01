#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 1e6 + 10;
int dp[N], sdp[N];
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    int S = 0;
    for(int i = 1; i <=n ; i ++)cin >> a[i], S += a[i];
    S = (S+1)/2;
    int sum = 0;
    sdp[0] = dp[0] = 1;
    //cout << S << '\n';
    for(int r = 1, l = 1; r <= n; r ++){
        sum += a[r];
        while(sum >= S && l <= r)sum-=a[l], l ++;
        dp[r] = (sdp[r-1] - (l >= 2 ? sdp[l-2] : 0)  + mod)%mod;
        sdp[r] = sdp[r-1] + dp[r];
        sdp[r] %= mod;
        //cout << dp[r] << '\n';
    }   
    cout << dp[n] << '\n';
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
