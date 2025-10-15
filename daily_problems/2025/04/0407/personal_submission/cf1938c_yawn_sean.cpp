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

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;
        
        vector<int> nums(n);
        for (auto &x: nums) 
            cin >> x;
        
        long long res = (1ll << nums[0]) - 1;
        for (int i = 1; i < n; i ++) {
            int cnt = nums[i - 1] - nums[i] + 1;
            if (cnt >= 0)
                res = max(res, (1ll << nums[i - 1] + 1) - (1ll << cnt) - i);
        }

        bool flg = true;
        for (int i = 0; i < n; i ++) {
            if (__popcount(res + i) != nums[i]) {
                flg = false;
            }
        }

        cout << (flg ? res : -1) << '\n';
    }

    return 0;
}