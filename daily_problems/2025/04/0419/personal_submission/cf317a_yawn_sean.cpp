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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

    long long x, y, m;
    cin >> x >> y >> m;

    if (x >= m || y >= m) cout << 0;
    else if (x <= 0 && y <= 0) cout << -1;
    else {
        long long ans = 0;
        if (x <= 0) {
            ans += ((-x) + y - 1) / y;
            x += ans * y;
        }
        if (y <= 0) {
            ans += ((-y) + x - 1) / x;
            y += ans * x;
        }

        while (x < m && y < m) {
            if (x > y) swap(x, y);
            x += y;
            ans ++;
        }
        cout << ans;
    }

    return 0;
}