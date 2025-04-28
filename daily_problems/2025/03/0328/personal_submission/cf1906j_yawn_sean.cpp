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
    for (auto &x: nums) cin >> x;

    int mod = 998244353;
    vector<int> prev(n);
    iota(prev.begin(), prev.end(), 0);

    for (int i = 1; i < n; i ++) {
        if (nums[i] > nums[i - 1]) {
            prev[i] = prev[i - 1];
        }
    }

    vector<int> dp(n, 0), acc(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i ++) {
        int pw = 1;
        for (int j = i - 1; j < n; j ++) {
            acc[j + 1] = (1ll * pw * dp[j] + acc[j]) % mod;
            pw += pw;
            if (pw >= mod) pw -= mod;
        }

        for (int j = i; j < n; j ++)
            dp[j] = (acc[j + 1] - acc[max(prev[j] - 1, 0)] + mod) % mod;
        
        for (int j = 0; j <= n; j ++)
            acc[j] = 0;
    }

    cout << dp[n - 1];

    return 0;
}