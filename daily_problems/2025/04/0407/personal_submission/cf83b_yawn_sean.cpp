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
    long long k;
    cin >> n >> k;

    vector<int> nums(n);
    long long total = 0;

    for (auto &x: nums)
        cin >> x, total += x;

    if (total < k) cout << -1;
    else {
        int l = 0, r = 1e9;
        while (l <= r) {
            int m = (l + r) / 2;
            long long v = 0;
            for (auto &x: nums)
                v += min(x, m);
            if (v <= k) l = m + 1;
            else r = m - 1;
        }

        vector<int> tmp;
        for (int i = 0; i < n; i ++) {
            if (nums[i] > r) tmp.emplace_back(i);
            k -= min(nums[i], r);
            nums[i] -= min(nums[i], r);
        }

        for (int i = 0; i < k; i ++)
            nums[tmp[i]] --;
        
        for (int i = k; i < tmp.size(); i ++)
            if (nums[tmp[i]]) cout << tmp[i] + 1 << ' ';
        
        for (int i = 0; i < k; i ++)
            if (nums[tmp[i]]) cout << tmp[i] + 1 << ' ';
    }

    return 0;
}