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

    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);
    long long v1 = 0, v2 = 0;

    for (auto &x: nums1)
        cin >> x, v1 += x;
    
    for (auto &x: nums2) 
        cin >> x, v2 += x;
    
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    __int128_t ans = 1e20;
    long long cur;

    cur = 0;
    for (int i = 0; i < n; i ++) {
        ans = min(ans, (__int128_t)1 * v2 * (n - i) + cur);
        cur += nums1[i];
    }

    cur = 0;
    for (int i = 0; i < m; i ++) {
        ans = min(ans, (__int128_t)1 * v1 * (m - i) + cur);
        cur += nums2[i];
    }

    cout << (long long) ans;

    return 0;
}