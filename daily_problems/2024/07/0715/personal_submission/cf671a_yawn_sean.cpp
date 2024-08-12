#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double ax, ay, bx, by, tx, ty, x, y;
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    function<double(void)> f1 = [&] () {
        return hypot(x - ax, y - ay);
    };

    function<double(void)> f2 = [&] () {
        return hypot(x - bx, y - by);
    };

    function<double(void)> f = [&] () {
        return hypot(x - tx, y - ty);
    };

    double ans = 0, dp1 = 4e9, dp2 = 4e9, dp3 = 4e9;
    int n;
    cin >> n;
    while (n --) {
        cin >> x >> y;
        ans += 2 * f();
        double v1 = f1() - f(), v2 = f2() - f();
        dp3 = min({dp3, dp1 + v2, dp2 + v1});
        dp2 = min(dp2, v2);
        dp1 = min(dp1, v1);
    }
    cout << setprecision(15) << ans + min({dp1, dp2, dp3});

    return 0;
}