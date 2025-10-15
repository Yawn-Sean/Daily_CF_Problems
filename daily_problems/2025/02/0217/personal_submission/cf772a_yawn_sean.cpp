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

    int n, p;
    cin >> n >> p;

    vector<pair<int, int>> devices(n);
    for (auto &[x, y]: devices) cin >> x >> y;

    sort(devices.begin(), devices.end(), [&] (pair<int, int> x, pair<int, int> y) {return 1ll * x.second * y.first < 1ll * x.first * y.second;});

    long long cur_x = 0, cur_y = -p;
    for (auto &[y, x]: devices) {
        if (cur_y <= 0 || cur_x * y > cur_y * x) {
            cur_x += x;
            cur_y += y;
        }
    }

    if (cur_y <= 0) cout << -1;
    else cout << fixed << setprecision(10) << (long double)1.0 * cur_x / cur_y;

    return 0;
}