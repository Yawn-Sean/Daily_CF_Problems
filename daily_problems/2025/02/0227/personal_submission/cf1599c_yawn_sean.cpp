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
    long double p;
    cin >> n >> p;

    for (int i = 0; i <= n; i ++) {
        long double prob = 0;
        prob += i * (i - 1) * (i - 2) / 6;
        prob += i * (i - 1) / 2 * (n - i);
        prob += 1.0 / 2 * i * (n - i) * (n - i - 1) / 2;
        if (prob / (n * (n - 1) * (n - 2) / 6) >= p) {
            cout << i;
            break;
        }
    }

    return 0;
}