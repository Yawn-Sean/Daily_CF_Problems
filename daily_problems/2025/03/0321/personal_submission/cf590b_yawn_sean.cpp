#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x1, y1, x2, y2, vm, vx, vy, wx, wy;
    long double t;
    cin >> x1 >> y1 >> x2 >> y2 >> vm >> t >> vx >> vy >> wx >> wy;

    x2 -= x1, y2 -= y1;
    long double l = 0, r = 1e9;

    for (int i = 0; i < 120; i ++) {
        long double m = (l + r) / 2;
        long double x = x2, y = y2;
        x -= min(m, t) * vx;
        y -= min(m, t) * vy;
        x -= (m - min(m, t)) * wx;
        y -= (m - min(m, t)) * wy;
        
        if (x * x + y * y <= vm * vm * m * m) r = m;
        else l = m;
    }

    cout << fixed << setprecision(20) << (l + r) / 2;

    return 0;
}