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
int dp[N][4], sum[N][4], l[4];
void solve()
{
    int n;
    cin >> n >> l[1] >> l[2] >> l[3];
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= 3; j ++){
            dp[i][j] += sum[i-1][j];
            if (i-l[j]-1 < 0)dp[i][j] ++;
            else dp[i][j] -= sum[i-l[j]-1][j];
            dp[i][j] %= mod;
            if (dp[i][j] < 0)dp[i][j] += mod;
            //cout << dp[i][j] <<' ';
        }
        //cout << '\n';
        sum[i][1] = sum[i-1][1] + dp[i][2] + dp[i][3];
        sum[i][2] = sum[i-1][2] + dp[i][1] + dp[i][3];
        sum[i][3] = sum[i-1][3] + dp[i][1] + dp[i][2];
        sum[i][1]%=mod;
        sum[i][2]%=mod;
        sum[i][3]%=mod;

    }
    cout << (dp[n][1] + dp[n][2] + dp[n][3])%mod << '\n';
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
