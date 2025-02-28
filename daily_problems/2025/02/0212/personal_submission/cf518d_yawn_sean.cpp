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

    int n, t;
    long double p;

    cin >> n >> p >> t;

    vector<long double> dp(n + 1, 0);
    dp[0] = 1;

    while (t --) {
        for (int i = n - 1; i >= 0; i --) {
            dp[i + 1] += dp[i] * p;
            dp[i] *= 1 - p;
        }
    }

    long double ans = 0;
    for (int i = 0; i <= n; i ++)
        ans += dp[i] * i;
    
    cout << fixed << setprecision(15) << ans;

    return 0;
}