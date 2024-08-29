#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long y1, y2, yw, xb, yb, r;
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;

    y1 = 2 * yw - 2 * r - y1;
    y2 = 2 * yw - 2 * r - y2;
    swap(y1, y2);

    __int128_t left = r * r, right = (y2 - y1 - r) * (y2 - y1 - r);
    left *= (yb - y2 + r) * (yb - y2 + r) + xb * xb;
    right *= xb * xb;

    if (left > right)
        cout << -1;
    else
        cout << setprecision(15) << 1.0 * (y2 - yw) * xb / (y2 - r - yb);

    return 0;
}