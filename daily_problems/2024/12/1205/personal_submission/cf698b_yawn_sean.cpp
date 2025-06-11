#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v, v --;
    
    int rt = -1;
    for (int i = 0; i < n; i ++) {
        if (nums[i] == i) {
            rt = i;
        }
    }

    int ans = 0;
    vector<int> vis(n, -1);

    for (int i = 0; i < n; i ++) {
        if (vis[i] == -1) {
            int u = i;
            while (vis[u] == -1) {
                vis[u] = i;
                u = nums[u];
            }

            if (vis[u] == i && u != rt) {
                ans ++;
                if (rt >= 0) nums[u] = rt;
                else {
                    nums[u] = u;
                    rt = u;
                }
            }
        }
    }

    cout << ans << '\n';
    for (auto &x: nums)
        cout << x + 1 << ' ';

    return 0;
}