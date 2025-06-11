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
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, d;
    cin >> n >> m >> d;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] < nums[j];});

    int l = 1, r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        bool flg = true;

        for (int i = m; i < n; i ++) {
            if (nums[order[i]] - nums[order[i - m]] <= d) {
                flg = false;
            }
        }

        if (flg) r = m - 1;
        else l = m + 1;
    }

    cout << l << '\n';

    vector<int> ans(n);

    for (int i = 0; i < n; i ++)
        ans[order[i]] = i % l + 1;
    
    for (auto &x: ans) cout << x << ' ';

    return 0;
}