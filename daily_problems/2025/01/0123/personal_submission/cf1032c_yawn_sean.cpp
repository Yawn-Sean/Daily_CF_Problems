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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums)
        cin >> x;

    vector<vector<int>> dp(6, vector<int>(n, -2));

    for (int i = 1; i <= 5; i ++)
        dp[i][0] = -1;
    
    for (int i = 1; i < n; i ++) {
        for (int j = 1; j <= 5; j ++) {
            if (dp[j][i - 1] != -2) {
                for (int nj = 1; nj <= 5; nj ++) {
                    if ((nums[i] > nums[i - 1] && nj > j) || 
                        (nums[i] == nums[i - 1] && nj != j) ||
                        (nums[i] < nums[i - 1] && nj < j)) {
                        dp[nj][i] = j;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= 5; i ++) {
        if (dp[i][n - 1] != -2) {
            vector<int> ans = {i};
            for (int j = n - 1; j > 0; j --)
                ans.emplace_back(dp[ans.back()][j]);

            reverse(ans.begin(), ans.end());
            for (auto &v: ans) cout << v << ' ';

            return 0;
        }
    }

    cout << -1;

    return 0;
}