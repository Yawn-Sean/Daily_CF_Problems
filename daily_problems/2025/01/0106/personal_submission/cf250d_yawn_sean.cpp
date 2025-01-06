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

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<int> nums1(n), nums2(m), nums3(m);
    for (auto &v: nums1) cin >> v;
    for (auto &v: nums2) cin >> v;
    for (auto &v: nums3) cin >> v;

    auto dis = [&] (int i, int j) -> long double {
        return sqrtl(1ll * a * a + 1ll * nums1[i] * nums1[i]) + sqrtl(1ll * (b - a) * (b - a) + 1ll * (nums2[j] - nums1[i]) * (nums2[j] - nums1[i])) + nums3[j];
    };

    long double ans = 1e9;
    int idx1 = -1, idx2 = -1, pt = 0;

    for (int i = 0; i < m; i ++) {
        while (pt < n - 1 && dis(pt, i) > dis(pt + 1, i))
            pt ++;
        
        long double nans = dis(pt, i);
        if (nans < ans)
            ans = nans, idx1 = pt, idx2 = i;
    }

    cout << idx1 + 1 << ' ' << idx2 + 1;

    return 0;
}