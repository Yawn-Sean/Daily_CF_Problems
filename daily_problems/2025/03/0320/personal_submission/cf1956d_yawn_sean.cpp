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

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    vector<int> dp(n + 1, 0), prev(n + 1, -1);
    for (int i = 1; i <= n; i ++) {
        int v;
        for (int j = 0; j < i; j ++) {
            v = dp[j] + (i - j) * (i - j);
            if (v > dp[i]) {
                dp[i] = v;
                prev[i] = j;
            }
        }
        v = dp[i - 1] + nums[i - 1];
        if (v > dp[i]) {
            dp[i] = v;
            prev[i] = i - 1;
        }
    }

    vector<pair<int, int>> ops;

    auto mex = [&] (int l, int r) -> int {
        set<int> vis;
        for (int i = l; i < r; i ++)
            vis.insert(nums[i]);
        for (int i = 0; i <= n; i ++)
            if (vis.find(i) == vis.end())
                return i;
        return -1;
    };

    auto op = [&] (int l, int r) -> int {
        ops.emplace_back(l, r);
        int v = mex(l, r);
        for (int i = l; i < r; i ++)
            nums[i] = v;
        return v;
    };

    auto set_zero = [&] (int l, int r) -> void {
        if (op(l, r)) op(l, r);
    };

    auto mid_process = [&] (auto &self, int l, int r) -> void {
        if (r < 0) return ;
        if (l + 1 == r) set_zero(l, r);
        else {
            self(self, l, r - 1);
            op(l, r);
            self(self, l, r - 1);
        }
    };

    auto process = [&] (int l, int r) -> void {
        set_zero(l, r);
        mid_process(mid_process, l, r);
        op(l, r);
    };

    int cur = n;

    while (cur) {
        int p = prev[cur];
        if (p < cur - 1 || nums[p] == 0)
            process(p, cur);
        cur = p;
    }

    cout << dp[n] << ' ' << ops.size() << '\n';
    for (auto &[x, y]: ops)
        cout << x + 1 << ' ' << y << '\n';

    return 0;
}