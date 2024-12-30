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
    for (auto &v: nums)
        cin >> v;
    
    int inf = 1e9, vn = n;

    if ((vn & 1) == 0)
        vn ++, nums.emplace_back(0);
    
    vector<vector<int>> dp(n / 2 + 1, vector<int>(vn, inf)), pre(n / 2 + 1, vector<int>(vn, -1));

    dp[0][0] = 0;
    for (int i = 0; i < n / 2; i ++) {
        for (int j = 0; j <= 2 * i; j ++) {
            int v;
            v = max(nums[j], nums[2 * i + 1]) + dp[i][j];
            if (v < dp[i + 1][2 * i + 2]) {
                dp[i + 1][2 * i + 2] = v;
                pre[i + 1][2 * i + 2] = j;
            }
            v = max(nums[j], nums[2 * i + 2]) + dp[i][j];
            if (v < dp[i + 1][2 * i + 1]) {
                dp[i + 1][2 * i + 1] = v;
                pre[i + 1][2 * i + 1] = j;
            }
            v = max(nums[2 * i + 1], nums[2 * i + 2]) + dp[i][j];
            if (v < dp[i + 1][j]) {
                dp[i + 1][j] = v;
                pre[i + 1][j] = j;
            }
        }
    }

    int ans = inf, idx = -1;
    for (int i = 0; i < vn; i ++) {
        if (dp[n / 2][i] + nums[i] < ans) {
            ans = dp[n / 2][i] + nums[i];
            idx = i;
        }
    }
    cout << ans << '\n';

    vector<pair<int, int>> chosen;
    chosen.emplace_back(idx, n);

    for (int i = n / 2; i > 0; i --) {
        int nidx = pre[i][idx];
        if (idx == 2 * i - 1) chosen.emplace_back(nidx, 2 * i);
        else if (idx == 2 * i) chosen.emplace_back(nidx, 2 * i - 1);
        else chosen.emplace_back(2 * i - 1, 2 * i);
        idx = nidx;
    }

    reverse(chosen.begin(), chosen.end());

    for (auto &[x, y]: chosen) {
        if (x < n) cout << x + 1 << ' ';
        if (y < n) cout << y + 1 << ' ';
        cout << '\n';
    }

    return 0;
}