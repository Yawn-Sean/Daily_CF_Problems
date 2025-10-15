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

    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;

    int c1 = 0, total = 0;
    for (int i = 0; i < k; i ++) {
        int v;
        cin >> v;
        c1 += v >= y;
        total += v;
    }

    int v_to_add = max((n + 1) / 2 - c1, 0);
    if (n - k < v_to_add || v_to_add * y + (n - k - v_to_add) + total > x) cout << -1;
    else {
        for (int i = 0; i < n - k - v_to_add; i ++)
            cout << "1 ";
        for (int i = 0; i < v_to_add; i ++)
            cout << y << ' ';
    }

    return 0;
}