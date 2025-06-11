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

    int n, k, mod;
    cin >> n >> k >> mod;

    vector<vector<int>> dp(2, vector<int>(k, 0)), ndp(2, vector<int>(k, 0));

    auto update = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod)
            x -= mod;
    };

    int cur = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 2; j ++) {
            for (int a = 0; a < k; a ++) {
                for (int b = 0; b < 10; b ++) {
                    if (i == n - 1 && b == 0) continue;
                    int na = (a + b * cur) % k;
                    int nj = j | (na == 0);
                    update(ndp[nj][na], dp[j][a]);
                }
            }
        }
        for (int b = 1; b < 10; b ++) {
            int na = b * cur % k;
            int nj = (na == 0);
            update(ndp[nj][na], 1);
        }
        for (int j = 0; j < 2; j ++) {
            for (int a = 0; a < k; a ++) {
                dp[j][a] = ndp[j][a];
                ndp[j][a] = 0;
            }
        }
        cur = cur * 10 % k;
    }
    int ans = 0;
    for (int i = 0; i < k; i ++)
        update(ans, dp[1][i]);
    
    cout << ans;

    return 0;
}