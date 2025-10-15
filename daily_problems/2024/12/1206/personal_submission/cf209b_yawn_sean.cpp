#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

    long long a, b, c;
    cin >> a >> b >> c;

    long long ans = 1ll << 31;
    if ((a ^ b ^ 1) & 1) ans = min(ans, max(a, b));
    if ((a ^ c ^ 1) & 1) ans = min(ans, max(a, c));
    if ((b ^ c ^ 1) & 1) ans = min(ans, max(b, c));

    cout << ans;

    return 0;
}