#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 998244353;
const int N = 1e6 + 10;
const double pi = acos(-1);
void solve()
{
    double a, x;
    cin >> a >> x;
    double up = 4.0 * x * x *sin(pi/4.0);
    if(a >= up){
        cout << fixed << setprecision(5) << up << '\n';
    }
    else{
        double af = asin(a/(4*x*x));
        double d = 2 * x * sin(af/2);
        double s = 2 * d * d / tan(pi/8);
        cout << fixed << setprecision(5) << s << '\n';
    }
    

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
