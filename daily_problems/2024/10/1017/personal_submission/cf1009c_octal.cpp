#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    ll n, m;
    cin >> n >> m;
    ll t = 0, y = 0;
    t = (1+n/2)*(n/2);
    if(n % 2 == 0) t -= n/2;
    y = n*(n-1) / 2;
    ll sum = 0;
    double res = 0;
    for(int i=1; i<=m; i++) {
        ll x, d;
        cin >> x >> d;
        res += x;
        if(d < 0) {
            sum += d * t;
        } else {
            sum += d * y;
        }
    }
    res += 1.0 * sum / n;
    // debug(sum);
    cout << res << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("F://桌面//test.in", "r", stdin);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
