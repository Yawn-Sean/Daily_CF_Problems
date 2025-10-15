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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    
    vector<int> ans(n, 1);
    int cur = nums.back();

    for (int i = n - 2; i >= 0; i --) {
        if (abs(cur + nums[i]) < abs(cur - nums[i])) {
            cur += nums[i];
        }
        else {
            cur -= nums[i];
            ans[i] = 0;
        }
    }

    if (cur < 0) {
        for (int i = 0; i < n; i ++) {
            ans[i] ^= 1;
        }
    }

    for (auto &x: ans)
        cout << (x ? '+' : '-');

    return 0;
}