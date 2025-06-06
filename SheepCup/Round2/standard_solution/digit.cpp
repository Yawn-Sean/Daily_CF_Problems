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

    int n, digit, mod = 1e9 + 7;
    string s;

    cin >> n >> digit >> s;

    vector<int> val(n, 0);
    for (int i = 0; i < s.size(); i ++) 
        val[i + n - s.size()] = s[i] - '0';
    
    vector<vector<int>> dp(2, vector<int>(n + 1, 0)), ndp(2, vector<int>(n + 1, 0));

    dp[0][0] = 1;
    dp[1][1] = 1;

    for (auto &c: val) {
        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j <= n; j ++) {
                for (int k = 0; k < 2; k ++) {
                    int v = k + (k ^ c) + i;
                    int oi = (v >= 2 ? 1 : 0), oj = j - (v & 1);
                    if (oj >= 0) {
                        ndp[i][j] += dp[oi][oj];
                        if (ndp[i][j] >= mod) ndp[i][j] -= mod;
                    }
                }
            }
        }
        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j <= n; j ++) {
                dp[i][j] = ndp[i][j];
                ndp[i][j] = 0;
            }
        }
    }

    cout << 1ll * dp[0][digit] * (s == "0" ? 1 : (mod + 1) / 2) % mod;

    return 0;
}