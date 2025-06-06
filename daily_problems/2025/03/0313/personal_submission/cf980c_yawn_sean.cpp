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

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    vector<int> col(256), sz(256, 1);
    iota(col.begin(), col.end(), 0);

    for (int i = 0; i < n; i ++) {
        while (true) {
            int cur = col[nums[i]];
            if (!cur) break;

            int ncur = col[cur - 1];
            if (sz[ncur] + sz[cur] > k) break;

            for (int j = cur; j <= nums[i]; j ++)
                col[j] = ncur;
            sz[ncur] += sz[cur];
        }
        cout << col[nums[i]] << ' ';
    }

    return 0;
}