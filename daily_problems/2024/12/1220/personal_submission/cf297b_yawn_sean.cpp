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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> nums1(n), nums2(m);
    for (auto &v: nums1) cin >> v;
    for (auto &v: nums2) cin >> v;

    sort(nums1.rbegin(), nums1.rend());
    sort(nums2.rbegin(), nums2.rend());

    if (n > m) cout << "YES";
    else {
        for (int i = 0; i < n; i ++) {
            if (nums1[i] > nums2[i]) {
                return cout << "YES", 0;
            }
        }
        cout << "NO";
    }

    return 0;
}