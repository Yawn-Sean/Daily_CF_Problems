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

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    int l = 0, r = 0, v = 0;
    int ans = -1, choice = -1;

    while (l < n) {
        while (r < n && v + 1 - nums[r] <= k) {
            v += 1 - nums[r];
            r ++;
        }

        if (r - l > ans) {
            ans = r - l;
            choice = l;
        }

        v -= 1 - nums[l];
        l ++;
    }

    for (int i = 0; i < ans; i ++)
        nums[choice + i] = 1;
    
    cout << ans << '\n';
    for (auto &x: nums) cout << x << ' ';

    return 0;
}