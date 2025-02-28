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

    int n, m, i, j, a, b, inf = 1e9;
    cin >> n >> m >> i >> j >> a >> b;

    auto f = [&] (int dx, int dy) -> int {
        if (dx % a || dy % b) return inf;
        dx /= a, dy /= b;
        if ((dx ^ dy) & 1) return inf;
        return max(dx, dy);
    };

    if ((i == 1 || i == n) && (j == 1 || j == m))
        cout << 0;
    else if (n <= a || m <= b)
        cout << "Poor Inna and pony!";
    else {
        int ans = inf;
        for (auto &x: {1, n}) {
            for (auto &y: {1, m}) {
                ans = min(ans, f(abs(x - i), abs(y - j)));
            }
        }
        if (ans < inf) cout << ans;
        else cout << "Poor Inna and pony!";
    }

    return 0;
}