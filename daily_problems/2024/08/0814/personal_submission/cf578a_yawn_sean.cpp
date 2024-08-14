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

    int x, y;
    cin >> x >> y;
    if (x < y)
        cout << -1;
    else {
        double ans = 1e9;
        int v;
        v = x - y;
        if (v >= 2 * y) {
            int k = v / (2 * y);
            ans = min(ans, 1.0 * v / 2 / k);
        }
        v = x + y;
        if (v >= 2 * y) {
            int k = v / (2 * y);
            ans = min(ans, 1.0 * v / 2 / k);
        }
        cout << setprecision(12) << ans;
    }

    return 0;
}