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

    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    cout << fixed << setprecision(15);
    if ((r2 - r1) * (r2 - r1) > (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) 
        cout << (fabsl(r2 - r1) - hypotl(x2 - x1, y2 - y1)) / 2;
    else if ((r2 + r1) * (r2 + r1) < (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) 
        cout << (hypotl(x2 - x1, y2 - y1) - r1 - r2) / 2;
    else cout << 0;

    return 0;
}