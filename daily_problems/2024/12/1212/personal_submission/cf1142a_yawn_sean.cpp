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

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    long long tot = 1ll * n * k;
    long long mi = tot, ma = 0;

    for (int i = 0; i < n; i ++) {
        long long x, res;
        x = 1ll * k * i + a + b;
        res = tot / gcd(x, tot);
        mi = min(mi, res), ma = max(ma, res);
        x = 1ll * k * i + a - b;
        res = tot / gcd(x, tot);
        mi = min(mi, res), ma = max(ma, res);
    }
    cout << mi << ' ' << ma;

    return 0;
}