#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<int> nums(m);
        for (auto &x: nums)
            cin >> x;

        sort(nums.begin(), nums.end());
        
        int to_consider = min(m, abs(a - b) - 1);
        int caught = (a < b ? b - 1 : n - b);

        int ans = 0;
        for (int i = to_consider - 1; i >= 0; i --) {
            if (nums[i] < caught) {
                caught --;
                ans ++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}