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

    int n, m;
    cin >> n >> m;

    vector<int> nums(m);
    for (auto &x: nums)
        cin >> x, x --;

    vector<int> vis(n + 1, -1), ans(n, -1);

    for (int i = 1; i < m; i ++) {
        int pos = nums[i - 1];
        int step = (nums[i] - nums[i - 1] + n - 1) % n + 1;

        if (vis[step] != -1 && vis[step] != pos)
            return cout << -1, 0;
        if (ans[pos] != -1 && ans[pos] != step)
            return cout << -1, 0;
        
        vis[step] = pos, ans[pos] = step;
    }

    int pt = 1;

    for (int i = 0; i < n; i ++) {
        if (ans[i] == -1) {
            while (vis[pt] != -1) pt ++;
            ans[i] = pt, vis[pt] = i;
        }
    }

    for (auto &x: ans) cout << x << ' ';

    return 0;
}