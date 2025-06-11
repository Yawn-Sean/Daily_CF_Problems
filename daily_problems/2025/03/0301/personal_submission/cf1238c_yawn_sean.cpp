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
    
    int t;
    cin >> t;

    while (t --) {
        int h, n;
        cin >> h >> n;

        vector<int> nums(n + 1, 0);
        for (int i = n; i > 0; i --)
            cin >> nums[i];
        
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i ++) {
            if (nums[i - 1] == nums[i - 2] + 1) dp[i] = dp[i - 2];
            else dp[i] = dp[i - 1] + 1;
        }

        cout << dp[n] << '\n';
    }

    return 0;
}