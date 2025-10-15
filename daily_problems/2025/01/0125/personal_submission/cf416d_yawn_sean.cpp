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

    int start = 0, i1 = -1, i2 = -1, ans = 1;

    for (int i = 0; i < n; i ++) {
        if (nums[i] == -1) {
            if (i2 != -1) {
                long long v = 1ll * (nums[i2] - nums[i1]) / (i2 - i1) * (i - i1) + nums[i1];
                if (v <= 0) {
                    ans ++;
                    start = i, i1 = -1, i2 = -1;
                }
            }
        }
        else {
            if (i1 == -1) i1 = i;
            else if (i2 == -1) {
                if ((nums[i] - nums[i1]) % (i - i1) || 1ll * (nums[i] - nums[i1]) / (i - i1) * (start - i1) + nums[i1] <= 0) {
                    ans ++;
                    start = i, i1 = i, i2 = -1;
                }
                else i2 = i;
            }
            else {
                long long v = 1ll * (nums[i2] - nums[i1]) / (i2 - i1) * (i - i1) + nums[i1];
                if (nums[i] != v) {
                    ans ++;
                    start = i, i1 = i, i2 = -1;
                }
            }
        }
    }

    cout << ans;

    return 0;
}