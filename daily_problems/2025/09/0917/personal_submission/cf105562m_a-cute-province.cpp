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
    int n;
    cin >> n;
    vector<PII> a(n+1);
    __int128_t x1 = 0, x2 =0, y1 = 0, y2 = 0;
    for(int i =0 ; i <n ; i++)cin >> a[i].x >> a[i].y, x2 += a[i].x, y2 += a[i].y;
    a[n] = a[0];
    __int128_t sum1 = 0, sum2 = 0;
    for(int i =1 ; i <=n ; i ++){
        sum1 += a[i].y * a[i-1].x;
    }
    for(int i =1 ; i <=n ; i ++){
        sum1 -= a[i].x * a[i-1].y;
    }
    if(sum1 < 0)sum1 = -sum1;
    for(int j = 0; j < n; j ++){
        x2 -= a[j].x, y2 -= a[j].y;
        __int128_t X1 = x1 - j * a[j].x, Y1 = y1 - j * a[j].y, X2 = x2 - (n-1-j) * a[j].x, Y2 = y2 -(n-1-j) * a[j].y;
        x1 += a[j].x, y1 += a[j].y;
        sum2 += X1*Y2 - X2 * Y1;
    }
    if(sum2 < 0)sum2 = -sum2;
    cout <<fixed << setprecision(10) << (long double)sum2 / sum1 << '\n';

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
