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

    int m;
    long double r;
    cin >> m >> r;

    long double r2 = sqrtl(2) * r;
    long double res = 0;

    res += (r * 2) * m;
    res += (r * 2 + r2) * (2 * (m - 1));
    res += (r2 * 2) * (m - 1) * (m - 2) + (r * 2) * (1ll * m * (m - 1) * (m - 2) / 3);

    cout << fixed << setprecision(15) << res / m / m;

    return 0;
}