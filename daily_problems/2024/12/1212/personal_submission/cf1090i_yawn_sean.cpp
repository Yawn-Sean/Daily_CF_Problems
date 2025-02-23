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

    int t;
    cin >> t;

    long long inf = 5e18;
    long long msk = (1ll << 32) - 1;

    while (t --) {
        long long n, l, r, x, y, z, b1, b2;
        cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;

        vector<int> nums(n);
        nums[0] = b1 % (r - l + 1) + l;
        nums[1] = b2 % (r - l + 1) + l;
        for (int i = 2; i < n; i ++) {
            b1 = (b1 * x + b2 * y + z) & msk;
            swap(b1, b2);
            nums[i] = b2 % (r - l + 1) + l; 
        }

        long long ans = inf;
        long long cur_mi = nums[0];

        for (int i = 0; i < n; i ++) {
            if (nums[i] <= cur_mi) cur_mi = nums[i];
            else ans = min(ans, cur_mi * nums[i]);
        }

        long long cur_ma = nums[n - 1];

        for (int i = n - 1; i >= 0; i --) {
            if (nums[i] >= cur_ma) cur_ma = nums[i];
            else ans = min(ans, cur_ma * nums[i]);
        }

        if (ans < inf) cout << ans << '\n';
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}