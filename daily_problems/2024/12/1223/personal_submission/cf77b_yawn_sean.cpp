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

    int t;
    cin >> t;

    cout << fixed << setprecision(10);
    while (t --) {
        int a, b;
        cin >> a >> b;
        if (b == 0) cout << 1 << '\n';
        else if (a == 0) cout << 0.5 << '\n';
        else if (4 * b > a) cout << 0.5 + 1.0 * a / 16 / b << '\n';
        else cout << 1 - 1.0 * b / a << '\n';
    }

    return 0;
}