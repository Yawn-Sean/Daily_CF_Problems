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
    string s;
    vector<int> nums(26);

    cin >> n >> s;
    for (auto &x: nums)
        cin >> x;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    int mod = 1e9 + 7;

    for (int i = 0; i < n; i ++) {
        int ma = n;
        for (int j = i; j < n; j ++) {
            ma = min(ma, nums[s[j] - 'a']);
            if (j - i + 1 > ma) break;
            dp[j + 1] += dp[i];
            if (dp[j + 1] >= mod) dp[j + 1] -= mod;
        }
    }

    cout << dp[n] << '\n';

    fill(dp.begin(), dp.end(), 0);

    for (int i = 0; i < n; i ++) {
        int ma = n;
        for (int j = i; j < n; j ++) {
            ma = min(ma, nums[s[j] - 'a']);
            if (j - i + 1 > ma) break;
            dp[j + 1] = max(dp[j + 1], max(dp[i], j + 1 - i));
        }
    }

    cout << dp[n] << '\n';

    fill(dp.begin(), dp.end(), n);
    
    dp[0] = 0;

    for (int i = 0; i < n; i ++) {
        int ma = n;
        for (int j = i; j < n; j ++) {
            ma = min(ma, nums[s[j] - 'a']);
            if (j - i + 1 > ma) break;
            dp[j + 1] = min(dp[j + 1], dp[i] + 1);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}