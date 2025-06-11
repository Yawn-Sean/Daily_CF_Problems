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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

    vector<int> nums1(n), nums2(n);
    map<int, int> mp;

    for (auto &x: nums1) cin >> x, mp[x] ++;
    for (auto &x: nums2) cin >> x, mp[x] ++;

    int to_divide = 0;
    for (int i = 0; i < n; i ++)
        to_divide += nums1[i] == nums2[i];
    
    int ans = 1, mod;
    cin >> mod;

    for (auto &[_, v]: mp) {
        for (int i = 1; i <= v; i ++) {
            int y = i;
            while (y % 2 == 0 && to_divide) {
                y >>= 1;
                to_divide --;
            }
            ans = 1ll * ans * y % mod;
        }
    }

    cout << ans;

    return 0;
}