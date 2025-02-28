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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, k, p;
    cin >> x >> k >> p;

    long double p1 = (long double)1.0 * p / 100, p2 = 1 - p1;

    vector<vector<long double>> dp(k + 1, vector<long double>(k + 1, 0));

    for (int i = 0; i <= k; i ++) {
        int v = x + i;
        v = v & -v;
        dp[0][i] = 31 - __builtin_clz(v);
    }

    for (int i = 0; i < k; i ++) {
        for (int j = 0; j <= k; j ++) {
            if (j * 2 <= k) dp[i + 1][j * 2] += p1 * (dp[i][j] + 1);
            if (j > 0) dp[i + 1][j - 1] += p2 * dp[i][j];
        }
    }

    cout << fixed << setprecision(25) << dp[k][0];

    return 0;
}