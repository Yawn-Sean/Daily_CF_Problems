#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    vector<int> xs(3), ys(3);
    for (int i = 0; i < 3; i ++)
        cin >> xs[i] >> ys[i];
    
    if ((xs[0] == xs[1] && xs[1] == xs[2]) || (ys[0] == ys[1] && ys[1] == ys[2]))
        cout << 1;
    else {
        for (int i = 0; i < 3; i ++) {
            int i1 = (i + 1) % 3, i2 = (i + 2) % 3;
            if (xs[i1] == xs[i2] && (ys[i] <= min(ys[i1], ys[i2]) || ys[i] >= max(ys[i1], ys[i2])))
                return cout << 2, 0;
            if (ys[i1] == ys[i2] && (xs[i] <= min(xs[i1], xs[i2]) || xs[i] >= max(xs[i1], xs[i2])))
                return cout << 2, 0;
        }
        cout << 3;
    }

    return 0;
}