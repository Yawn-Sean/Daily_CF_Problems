#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
 
void solve()
{
    int y1,y2,yw,xb,yb,r;
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;
    
    y1 = 2 * (yw - r) - y1;
    y2 = 2 * (yw - r) - y2;
    swap(y1,y2);
    // 直线方程 和 距离   |ax + by + c| / sprt(a**2 + b**2)
    // (0, y2), a || k = yb - ( y1 - r ) / xb
    // c = y2 - r
    __int128_t sdiv2 = (__int128_t)pow(xb *  (-y1 + y2 - r),2);
    __int128_t fdiv2 =  (__int128_t)pow(yb - (y2 - r),2) + (__int128_t)pow(xb,2);
    
    if(r*r * fdiv2 > sdiv2) cout << -1 << endl;
    else{
        cout << fixed << setprecision(10) << 1.0 * xb * (y2 - yw) / (y2 - yb - r);
    }
}
 
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
