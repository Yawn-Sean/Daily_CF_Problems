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

    int n, k;
    long long m;
    cin >> n >> k >> m;

    vector<long long> nums(k);
    for (auto &x: nums)
        cin >> x;
    
    sort(nums.begin(), nums.end());
    for (int i = 1; i < k; i ++)
        nums[i] += nums[i - 1];

    long long inf = 1e18;

    vector<long long> dp(n * (k + 1) + 1, inf);
    dp[0] = 0;

    for (int i = 0; i < n; i ++) {
        for (int j = n * (k + 1); j >= 0; j --) {
            for (int v = 0; v < k - 1; v ++) {
                if (j - v - 1 >= 0) {
                    dp[j] = min(dp[j], dp[j - v - 1] + nums[v]);
                }
            }
            if (j >= k + 1) {
                dp[j] = min(dp[j], dp[j - k - 1] + nums[k - 1]);
            }
        }
    }

    for (int i = n * (k + 1); i >= 0; i --) {
        if (dp[i] <= m) {
            return cout << i, 0;
        }
    }

    return 0;
}