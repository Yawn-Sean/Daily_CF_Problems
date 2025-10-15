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

    vector<int> nums(n);
    int total = 0;
    for (auto &x: nums) cin >> x, total += x;

    int p;
    cin >> p;

    if (total <= p) return cout << n, 0;

    vector<long double> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i ++)
        f[i] = i * f[i - 1];

    long double ans = 0;

    for (int i = 0; i < n; i ++) {
        vector<vector<long double>> dp(n + 1, vector<long double>(p + 1, 0));

        dp[0][0] = 1;

        for (int j = 0; j < n; j ++) {
            if (i != j) {
                for (int x = n; x > 0; x --) {
                    for (int y = p; y >= nums[j]; y --) {
                        dp[x][y] += dp[x - 1][y - nums[j]];
                    }
                }
            }
        }

        for (int j = 0; j < n; j ++) {
            for (int v = 0; v <= p; v ++) {
                if (v + nums[i] > p) {
                    ans += f[j] * f[n - 1 - j] * dp[j][v] * j;
                }
            }
        }

    }

    cout << fixed << setprecision(20) << ans / f[n];

    return 0;
}