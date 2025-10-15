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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int inf = 1e6, total_w = 0;
    vector<int> dp(201, -inf);
    dp[0] = 0;

    for (int i = 0; i < n; i ++) {
        int t, w;
        cin >> t >> w;

        total_w += w;
        for (int i = 200; i >= t; i --)
            dp[i] = max(dp[i], dp[i - t] + w);
    }

    for (int i = 0; i < 200; i ++) {
        if (total_w - dp[i] <= i) {
            cout << i;
            break;
        }
    }

    return 0;
}