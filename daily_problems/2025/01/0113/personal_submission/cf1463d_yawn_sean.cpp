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

        vector<int> nums(n), vis(2 * n + 1), other;
        for (auto &v: nums)
            cin >> v, vis[v] = 1;
        
        for (int i = 1; i <= 2 * n; i ++)
            if (!vis[i]) other.emplace_back(i);
        
        int l, r, mi, ma;

        l = 0, r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            bool flg = true;

            for (int i = 0; i < m; i ++) {
                if (nums[i] > other[n - m + i]) {
                    flg = false;
                }
            }

            if (flg) l = m + 1;
            else r = m - 1;
        }

        ma = r;

        l = 0, r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            bool flg = true;
            
            for (int i = m; i < n; i ++) {
                if (nums[i] < other[i - m]) {
                    flg = false;
                }
            }

            if (flg) r = m - 1;
            else l = m + 1;
        }

        mi = l;
        cout << ma - mi + 1 << '\n';
    }

    return 0;
}