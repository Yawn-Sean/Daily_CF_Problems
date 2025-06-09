#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    int n, m, s, e;
    cin >> n >> m >> s >> e;

    vector<int> nums1(n), nums2(m);
    for (auto &v: nums1) cin >> v;
    for (auto &v: nums2) cin >> v;

    vector<vector<int>> pos2(100001);

    for (int i = 0; i < m; i ++)
        pos2[nums2[i]].emplace_back(i);
    
    int inf = 1e6;
    vector<int> dp(n + 1, 0), ndp(n + 1, inf);

    int ans = 0;

    for (int op = 1; op <= s / e; op ++) {
        int cur = inf;

        for (int i = 1; i <= n; i ++) {
            cur = min(cur, dp[i - 1]);
            int p = lower_bound(pos2[nums1[i - 1]].begin(), pos2[nums1[i - 1]].end(), cur) - pos2[nums1[i - 1]].begin();
            if (p < pos2[nums1[i - 1]].size()) ndp[i] = pos2[nums1[i - 1]][p] + 1;
        }

        for (int i = 0; i <= n; i ++) {
            dp[i] = ndp[i];
            ndp[i] = inf;
        }

        for (int i = 1; i <= n; i ++) {
            if (dp[i] < inf && op * e + i + dp[i] <= s) {
                ans = op;
            }
        }
    }

    cout << ans;

    return 0;
}