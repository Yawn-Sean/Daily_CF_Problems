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
            cin >> v, v /= 100;
        
        sort(nums.rbegin(), nums.rend());

        int x, a, y, b;
        cin >> x >> a >> y >> b;

        if (x > y) swap(x, y), swap(a, b);

        long long k;
        cin >> k;

        int l = 1, r = n;

        while (l <= r) {
            int m = (l + r) / 2;

            int ca = 0, cb = 0, cab = 0;
            for (int i = 1; i <= m; i ++) {
                if (i % a == 0) {
                    if (i % b == 0) cab ++;
                    else ca ++;
                }
                else if (i % b == 0) cb ++;
            }

            long long cur = 0;
            for (int i = 0; i < n; i ++) {
                if (cab) cab --, cur += nums[i] * (x + y);
                else if (cb) cb --, cur += nums[i] * y;
                else if (ca) ca --, cur += nums[i] * x;
            }

            if (cur >= k) r = m - 1;
            else l = m + 1;
        }

        cout << (l <= n ? l : -1) << '\n';
    }

    return 0;
}