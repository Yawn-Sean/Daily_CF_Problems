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

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (auto &v: nums)
            cin >> v;
        
        int m;
        cin >> m;

        vector<int> v(n + 1, 0);
        while (m --) {
            int p, s;
            cin >> p >> s;
            v[s] = max(v[s], p);
        }

        for (int i = n - 1; i >= 1; i --)
            v[i] = max(v[i], v[i + 1]);
        
        int start = 0, cur = 0, ans = 1;
        for (int i = 0; i < n; i ++) {
            if (v[1] < nums[i]) ans = -n - 10;
            cur = max(cur, nums[i]);
            if (v[i - start + 1] < cur) {
                start = i;
                cur = nums[i];
                ans ++;
            }
        }

        cout << (ans > 0 ? ans : -1) << '\n';
    }

    return 0;
}