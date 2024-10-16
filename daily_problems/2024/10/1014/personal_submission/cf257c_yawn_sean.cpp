#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long double> angles(n);

    for (int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        angles[i] = atan2l(y, x);
    }

    sort(angles.begin(), angles.end());

    long double ans = 0, pi = atan2l(0, -1);

    for (int i = 1; i < n; i ++)
        ans = max(ans, angles[i] - angles[i - 1]);

    cout << setprecision(20) << min(2 * pi - ans, angles[n - 1] - angles[0]) / pi * 180;

    return 0;
}