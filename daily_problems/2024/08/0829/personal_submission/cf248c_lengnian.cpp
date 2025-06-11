#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
// #define int long long
long double init(int y1, int yw, int yb)
{
    return ( long double)(yw - y1) / ( long double)(yw - yb);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

     long double y1, y2, yw, xb, yb, r;
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;

    long double pos = init(y1 + r, yw - r, yb);
     long double ans = (xb / (pos + 1)) * pos;

     long double ios = atan(ans / (yw - 2 * r - y1));
    if ((y2 - y1 - r) * sin(ios) < r)
    {
        cout << "-1";
    }
    else
    {
        cout  << setprecision(15) << ans;
    }

    return 0;
}
