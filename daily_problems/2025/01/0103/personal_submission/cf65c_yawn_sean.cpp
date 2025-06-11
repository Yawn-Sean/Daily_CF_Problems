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
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> xs(n + 1), ys(n + 1), zs(n + 1);
    for (int i = 0; i <= n; i ++)
        cin >> xs[i] >> ys[i] >> zs[i];

    int vp, vs, px, py, pz;
    cin >> vp >> vs >> px >> py >> pz;

    auto dis = [&] (long double x1, long double y1, long double z1, long double x2, long double y2, long double z2) -> long double {
        return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
    };

    cout << fixed << setprecision(20);
    long double cur_time = 0;
    for (int i = 0; i < n; i ++) {
        long double new_time = dis(xs[i], ys[i], zs[i], xs[i + 1], ys[i + 1], zs[i + 1]) / vs;
        long double time = dis(px, py, pz, xs[i + 1], ys[i + 1], zs[i + 1]) / vp;
        if (time <= cur_time + new_time) {
            long double l = 0, r = 1, m, nx, ny, nz;
            for (int j = 0; j < 50; j ++) {
                m = (l + r) / 2;
                nx = xs[i] + m * (xs[i + 1] - xs[i]);
                ny = ys[i] + m * (ys[i + 1] - ys[i]);
                nz = zs[i] + m * (zs[i + 1] - zs[i]);
                if (dis(px, py, pz, nx, ny, nz) / vp <= cur_time + dis(xs[i], ys[i], zs[i], nx, ny, nz) / vs) r = m;
                else l = m;
            }
            cout << "YES\n";
            cout << dis(px, py, pz, nx, ny, nz) / vp << '\n';
            cout << nx << ' ' << ny << ' ' << nz;
            return 0;
        }
        cur_time += new_time;
    }
    cout << "NO";

    return 0;
}