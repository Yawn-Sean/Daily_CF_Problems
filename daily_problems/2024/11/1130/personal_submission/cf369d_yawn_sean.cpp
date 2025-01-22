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

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> must_kill(n + 1, 0), cant_kill(n + 1, 1);

    for (int i = n - 1; i >= 0; i --) {
        must_kill[i] = must_kill[i + 1] | (nums[i] == 100);
        cant_kill[i] = cant_kill[i + 1] & (nums[i] == 0);
    }

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 4000));
    dp[0][1] = 0;

    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (dp[i][j] < n) {
                if (!must_kill[j] && nums[i])
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
                if (!cant_kill[j] && nums[i] < 100)
                    dp[j][j + 1] = min(dp[j][j + 1], dp[i][j] + 1);
                if (!cant_kill[j] && nums[i])
                    dp[j + 1][j + 2] = min(dp[j + 1][j + 2], dp[i][j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= n + 1; j ++) {
            ans += (dp[i][j] <= k);
        }
    }
    
    cout << ans;

    return 0;
}