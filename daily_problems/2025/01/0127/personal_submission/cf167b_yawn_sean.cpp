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

    int n, l, k;
    cin >> n >> l >> k;

    vector<int> probs(n), vals(n);

    for (auto &v: probs) cin >> v;
    for (auto &v: vals) cin >> v;

    vector<vector<long double>> dp(n + 1, vector<long double>(201, 0)), ndp(n + 1, vector<long double>(201, 0));

    dp[0][k] = 1;

    for (int idx = 0; idx < n; idx ++) {
        if (vals[idx] >= 0) {
            for (int i = 0; i <= n; i ++) {
                for (int j = 0; j <= 200; j ++) {
                    if (dp[i][j]) {
                        long double p = (long double)1.0 * probs[idx] / 100;
                        ndp[i][j] += (-p + 1) * dp[i][j];
                        ndp[i + 1][min(j + vals[idx], 200)] += p * dp[i][j];
                    }
                }
            }
            for (int i = 0; i <= n; i ++) {
                for (int j = 0; j <= 200; j ++) {
                    dp[i][j] = ndp[i][j];
                    ndp[i][j] = 0;
                }
            }
        }
    }

    for (int idx = 0; idx < n; idx ++) {
        if (vals[idx] == -1) {
            for (int i = 0; i <= n; i ++) {
                for (int j = 0; j <= 200; j ++) {
                    if (dp[i][j]) {
                        long double p = (long double)1.0 * probs[idx] / 100;
                        ndp[i][j] += (-p + 1) * dp[i][j];
                        if (j) ndp[i + 1][j - 1] += p * dp[i][j];
                    }
                }
            }
            for (int i = 0; i <= n; i ++) {
                for (int j = 0; j <= 200; j ++) {
                    dp[i][j] = ndp[i][j];
                    ndp[i][j] = 0;
                }
            }
        }
    }

    long double ans = 0;
    for (int i = l; i <= n; i ++) {
        for (int j = 0; j <= 200; j ++) {
            ans += dp[i][j];
        }
    }

    cout << fixed << setprecision(15) << ans;

    return 0;
}