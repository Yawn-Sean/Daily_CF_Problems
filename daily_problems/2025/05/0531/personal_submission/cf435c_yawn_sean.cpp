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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n + 1);

    int total = 0;

    for (int i = 1; i <= n; i ++) {
        cin >> nums[i];
        total += nums[i];
    }

    for (int i = 1; i <= n; i ++)
        nums[i] = (i & 1 ? nums[i - 1] - nums[i] : nums[i - 1] + nums[i]);

    int mi = *min_element(nums.begin(), nums.end());
    int ma = *max_element(nums.begin(), nums.end());

    for (int i = 0; i <= n; i ++)
        nums[i] -= mi;
    
    vector<string> ans(ma - mi, string(total, ' '));

    int cur = 0;
    for (int i = 0; i < n; i ++) {
        int l = nums[i], r = nums[i + 1];
        if (l < r) {
            for (int j = 0; j < nums[i + 1] - nums[i]; j ++)
                ans[nums[i] + j][cur + j] = '\\';
            cur += r - l;
        }
        else {
            for (int j = 0; j < nums[i] - nums[i + 1]; j ++)
                ans[nums[i] - 1 - j][cur + j] = '/';
            cur += l - r;
        }
    }

    for (auto &x: ans) cout << x << '\n';

    return 0;
}