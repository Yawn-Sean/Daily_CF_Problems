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
const int mod = 1e9 + 7;
const double pi = acos(-1);
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n+1), sum(n+1), pre(n+1, -1e18), sub(n+2, -1e18);
    for(int i = 1; i <= n; i++)cin >> a[i], sum[i] = sum[i-1] + a[i];
    for(int i = 1; i <= n; i++){
        pre[i] = max(pre[i-1], (a[i]&y) - a[i]);
    }
    for(int i = n; i >= 1; i--){
        sub[i] = max(sub[i+1], (a[i]&y) - a[i]);
    }
    int ans = 1e18;
    for(int i = 1; i <= n; i++){
        ans = min(ans, sum[n] + (a[i]|x) -a[i] + max(max(pre[i-1], sub[i+1]), ((a[i]|x)&y) -(a[i]|x)));
    }
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
    cin >> t;
    //t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
