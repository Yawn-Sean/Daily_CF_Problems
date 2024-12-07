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

    vector<int> nums(n + 1), vals(n + 1, 0);
    for (auto &v: nums)
        cin >> v;
    
    for (int i = 0; i < n; i ++) {
        int x = (nums[i] + vals[i]) / 2;
        vals[i] = (nums[i] + vals[i]) % 2;
        vals[i + 1] += x;
    }
    vals[n] += nums[n];

    int idx = -1;
    for (int i = 0; i <= n; i ++) {
        if (vals[i] != 0) {
            idx = i;
            break;
        }
    }

    long long cur = 0;
    int ans = 0;

    for (int i = n; i >= 0; i --) {
        cur = cur * 2 + vals[i];
        if (abs(cur) > 2 * k) break;
        if (i <= idx && abs(nums[i] - cur) <= k && !(i == n && nums[i] == cur)) ans ++;
    }

    cout << ans;

    return 0;
}