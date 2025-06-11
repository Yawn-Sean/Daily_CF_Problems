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

    int n, s, k;
    cin >> n >> s >> k;
    s --;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    string cols;
    cin >> cols;

    int inf = 1e9;
    vector<vector<int>> dp(n, vector<int>(k + 1, inf));

    for (int i = 0; i < n; i ++)
        dp[i][min(nums[i], k)] = abs(i - s);

    vector<int> st_range(n);
    iota(st_range.begin(), st_range.end(), 0);
    sort(st_range.begin(), st_range.end(), [&] (int i, int j) {return nums[i] < nums[j];});

    for (int i = 0; i < n; i ++) {
        int i1 = st_range[i];
        for (int j = 0; j < n; j ++) {
            int j1 = st_range[j];
            if (nums[i1] <= nums[j1]) break;
            if (cols[i1] != cols[j1]) {
                for (int v = 0; v <= k; v ++) {
                    dp[i1][min(v + nums[i1], k)] = min(dp[i1][min(v + nums[i1], k)], dp[j1][v] + abs(i1 - j1));
                }
            }
        }
    }

    int ans = inf;
    for (int i = 0; i < n; i ++)
        ans = min(ans, dp[i][k]);
    
    cout << (ans < inf ? ans : -1);

    return 0;
}