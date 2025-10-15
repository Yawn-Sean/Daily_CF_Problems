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
    
    int k = (n + 1) / 2;

    int inf = 1e9;
    vector<int> cost(n);
    for (int i = 0; i < n; i ++) {
        if (i) cost[i] += max(nums[i - 1] - nums[i] + 1, 0);
        if (i < n - 1) cost[i] += max(nums[i + 1] - nums[i] + 1, 0);
    }

    vector<int> dp = cost, ndp(n, inf), pref(n);
    cout << *min_element(dp.begin(), dp.end()) << ' ';

    for (int i = 1; i < k; i ++) {
        pref[0] = dp[0];
        for (int j = 1; j < n; j ++) 
            pref[j] = min(pref[j - 1], dp[j]);
        
        for (int j = n - 1; j >= 2; j --)
            dp[j] = min(dp[j - 2] + cost[j] - max(nums[j - 1] - max(nums[j], nums[j - 2]) + 1, 0), pref[j - 2] + cost[j]);
        
        dp[0] = inf, dp[1] = inf;
        cout << *min_element(dp.begin(), dp.end()) << ' ';
    }

    return 0;
}