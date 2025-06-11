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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int s, a, b, c;
    cin >> s >> a >> b >> c;

    cout << fixed << setprecision(20);
    if (a || b || c) {
        int tot = a + b + c;
        cout << 1.0 * s * a / tot << ' ' << 1.0 * s * b / tot << ' ' << 1.0 * s * c / tot;
    }
    else {
        cout << 0 << ' ' << 0 << ' ' << s;
    }

    return 0;
}