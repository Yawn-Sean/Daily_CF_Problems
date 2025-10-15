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

    if (n & 1) cout << -1;
    else {
        for (int i = 0; i < n; i ++) {
            if (i) cout << '\n';
            for (int j = 0; j < n; j ++) {
                for (int k = 0; k < n; k ++) {
                    cout << ((i & 1) ^ ((j >> 1) & 1) ^ ((k >> 1) & 1) ? 'w' : 'b');
                }
                cout << '\n';
            }
        }
    }

    return 0;
}