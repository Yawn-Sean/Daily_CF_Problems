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
const int N = 2000 + 10;

void solve()
{
    int n, k;
    cin >> n >> k;
    n = min(n, k);
    vector<int> dp(k+1, 1);
    for(int i = 2; i <= n; i ++){
        vector<int> ndp(k+1), pre(k+1);
        for(int i = 1; i <=k;  i++)pre[i] = pre[i-1] + dp[i], pre[i] %= mod;
        for(int j = 1; j <= k ; j ++){
            int R = (i*j-1)/(i-1), L = (i*j-k + i-2)/(i-1);
            R = min(R, k);
            L = max(1ll, L);
            if(L > R)continue;
            ndp[j] = (pre[R] - pre[L-1] + mod) %mod;

        }
        dp = ndp;
    }
    int ans = 0;
    for(int i = 1; i <= k; i ++)ans += dp[i], ans %= mod;
    cout << ans << '\n';
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
