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

    int n, m, mod = 1e9 + 7;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<int>> dp(2001, vector<int>(2001, 0));
    dp[0][0] = 1;

    auto update = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    for (int i = 0; i < 2000; i ++) {
        for (int j = 0; j <= i; j ++) { 
            update(dp[i + 1][j + 1], dp[i][j]);
            if (j) update(dp[i + 1][j - 1], dp[i][j]);
        }
    }

    int cur = 0, cur_min = 0;

    for (auto &c: s) {
        cur += (c == '(' ? 1 : -1);
        cur_min = min(cur_min, cur);
    }

    int ans = 0;
    for (int i = 0; i <= n - m; i ++) {
        for (int j = 0; j <= 2000; j ++) {
            if (j + cur_min >= 0 && j + cur >= 0 && j + cur <= 2000) {
                update(ans, 1ll * dp[i][j] * dp[n - m - i][j + cur] % mod);
            }
        }
    }

    cout << ans;

    return 0;
}