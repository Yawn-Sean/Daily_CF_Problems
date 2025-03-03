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

    int n, d;
    cin >> n >> d;

    vector<int> nums;

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;

        if (d % 2 && x % 2 == 0) continue;
        if (d % 5 && x % 5 == 0) continue;
        nums.emplace_back(x);
    }

    n = nums.size();

    int inf = 1e9 + 10, bound = 1e6;

    vector<vector<int>> dp(10, vector<int>(n + 1, inf)), prev(10, vector<int>(n + 1, -1));

    dp[1][0] = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 10; j ++) {
            if (dp[j][i] <= bound && dp[j][i + 1] > dp[j][i] * nums[i]) {
                dp[j][i + 1] = dp[j][i] * nums[i];
                prev[j][i + 1] = j;
            }
            int nj = j * nums[i] % 10;
            if (dp[nj][i + 1] > dp[j][i]) {
                dp[nj][i + 1] = dp[j][i];
                prev[nj][i + 1] = j;
            }
        }
    }

    if (dp[d][n] < inf) {
        vector<int> ans;
        int cur_d = d;

        for (int i = n; i > 0; i --) {
            int p = prev[cur_d][i];
            if (dp[p][i - 1] == dp[cur_d][i] || nums[i - 1] == 1) {
                cur_d = p;
                ans.emplace_back(nums[i - 1]);
            }
        }
        
        if (!ans.empty()) {
            cout << ans.size() << '\n';
            for (auto &x: ans) cout << x << ' ';
        }
        else cout << -1;
    }
    else cout << -1;

    return 0;
}