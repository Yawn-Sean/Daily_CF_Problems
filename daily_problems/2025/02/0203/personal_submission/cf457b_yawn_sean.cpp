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

    vector<long long> nums1(n), nums2(m);
    long long v1 = 0, v2 = 0;

    for (auto &x: nums1)
        cin >> x, v1 += x;
    
    for (auto &x: nums2) 
        cin >> x, v2 += x;
    
    long long ans1 = 0, ans2 = 0;
    
    for (auto &x: nums1)
        ans1 += min(v2, x);
    ans1 += v2 - min(*max_element(nums1.begin(), nums1.end()), v2);

    for (auto &x: nums2)
        ans2 += min(v1, x);
    ans2 += v1 - min(*max_element(nums2.begin(), nums2.end()), v1);

    cout << min(ans1, ans2);

    return 0;
}