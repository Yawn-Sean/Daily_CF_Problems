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

    int n, m;
    cin >> n >> m;

    vector<int> cnt_r(n, 0), cnt_c(n, 0);
    int v1 = n, v2 = n;

    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        if (!cnt_r[x]) cnt_r[x] = 1, v1 --;
        if (!cnt_c[y]) cnt_c[y] = 1, v2 --;
    }

    vector<vector<long double>> dp(v1 + 2, vector<long double>(v2 + 2, 0));

    for (int i = v1; i >= 0; i --) {
        for (int j = v2; j >= 0; j --) {
            if (i == v1 && j == v2) continue;
            dp[i][j] = (long double)1.0 * (n * n 
                    + (v1 - i) * (v2 - j) * dp[i + 1][j + 1]
                    + (v1 - i) * (n - v2 + j) * dp[i + 1][j]
                    + (n - v1 + i) * (v2 - j) * dp[i][j + 1]) / (n * n - (n - v1 + i) * (n - v2 + j));
        }
    }

    cout << fixed << setprecision(20) << dp[0][0];

    return 0;
}