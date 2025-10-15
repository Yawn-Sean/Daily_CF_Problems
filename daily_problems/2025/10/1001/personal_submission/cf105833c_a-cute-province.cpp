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

void solve() {
    int n;
    cin >> n;
    vector<int> h(n+1), d(n+1), c(n+1), dp(5005, -1e18);
    for(int i = 1; i <=n ;i ++)cin >> h[i];
    for(int i = 1; i <=n ;i ++)cin >> d[i];
    for(int i = 1; i <=n ;i ++)cin >> c[i];
    dp[0] = 0;
    for(int i = n; i >= 1; i --){
        for(int j = 5000; j >= 0; j --){
            int nj = min(j + d[i], 5000ll);
            dp[nj] = max(dp[nj], dp[j]-c[i]);
        }
        for(int j = 0; j <= 5000; j ++){
            dp[j] += min(h[i], j);
        }
    }
    cout << *max_element(dp.begin(), dp.end());

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
