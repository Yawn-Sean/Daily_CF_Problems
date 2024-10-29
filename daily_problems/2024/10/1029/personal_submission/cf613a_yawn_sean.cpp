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

    int n, x0, y0;
    cin >> n >> x0 >> y0;

    __int128_t mi1 = 1e15, mi2 = 1, ma = 0;

    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; i ++) {
        cin >> xs[i] >> ys[i];
        xs[i] -= x0;
        ys[i] -= y0;

        __int128_t v = 1ll * xs[i] * xs[i] + 1ll * ys[i] * ys[i];
        if (v < mi1) mi1 = v;
        if (v > ma) ma = v;
    }

    for (int i = 0; i < n; i ++) {
        __int128_t x1 = xs[i], y1 = ys[i];
        __int128_t x2 = xs[(i + 1) % n], y2 = ys[(i + 1) % n];

        __int128_t v1 = x1 * x1 + y1 * y1;
        __int128_t v2 = x2 * x2 + y2 * y2;
        __int128_t v = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

        if (v1 + v > v2 && v2 + v > v1) {
            __int128_t a = (x1 * y2 - x2 * y1) * (x1 * y2 - x2 * y1);
            if (a * mi2 < v * mi1)
                mi1 = a, mi2 = v;
        }
    }

    cout << fixed << setprecision(20) << acos(-1) * (ma * mi2 - mi1) / mi2;

    return 0;
}