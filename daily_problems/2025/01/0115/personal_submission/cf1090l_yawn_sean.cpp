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

    int t, n, a, b, k;
    cin >> t >> n >> a >> b >> k;

    int v2 = n / 2, v1 = n - v2;
    long long ans = min((long long)t, (1ll * v1 * a + 1ll * v2 * b) / k);
    if (k > v1) ans = min(ans, 1ll * v2 * b / (k - v1));
    if (k > v2) ans = min(ans, 1ll * v1 * a / (k - v2));

    cout << (k <= n ? ans : 0);

    return 0;
}