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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums)
        cin >> x;

    if (n > 1 && (n & 1)) {
        int ans = 0;
        for (int i = n - 1; i >= 0; i --) {
            if (2 * i + 2 < n) {
                int v = max(nums[2 * i + 1], nums[2 * i + 2]);
                nums[i] = max(0, nums[i] - v);
                ans += v;
            }
        }
        cout << ans + nums[0];
    }
    else cout << -1;

    return 0;
}