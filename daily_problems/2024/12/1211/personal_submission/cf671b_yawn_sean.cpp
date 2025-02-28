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

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    long long tot = 0;

    for (auto &v: nums)
        cin >> v, tot += v;
    
    int l, r;
    int ans = 0;

    l = *min_element(nums.begin(), nums.end()), r = tot / n;

    while (l <= r) {
        int m = l + (r - l) / 2, cur = 0;
        for (auto &v: nums) {
            cur += max(m - v, 0);
            if (cur > k) break;
        }
        if (cur > k) r = m - 1;
        else l = m + 1;
    }

    ans -= r;

    l = (tot + n - 1) / n, r = *max_element(nums.begin(), nums.end());

    while (l <= r) {
        int m = l + (r - l) / 2, cur = 0;
        for (auto &v: nums) {
            cur += max(v - m, 0);
            if (cur > k) break;
        }
        if (cur > k) l = m + 1;
        else r = m - 1;
    }

    ans += l;

    cout << ans;

    return 0;
}