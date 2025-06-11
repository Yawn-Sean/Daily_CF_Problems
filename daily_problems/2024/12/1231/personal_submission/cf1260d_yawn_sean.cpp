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

    int m, n, k, t;
    cin >> m >> n >> k >> t;

    vector<int> nums(m);
    for (auto &v: nums) cin >> v;

    vector<int> ls(k), rs(k), ds(k);
    for (int i = 0; i < k; i ++)
        cin >> ls[i] >> rs[i] >> ds[i];
    
    sort(nums.rbegin(), nums.rend());
    int l = 1, r = m;
    vector<int> diff(n + 1, 0);

    while (l <= r) {
        int mid = (l + r) / 2;
        for (int i = 0; i < k; i ++) {
            if (nums[mid - 1] < ds[i]) {
                diff[ls[i] - 1] ++;
                diff[rs[i]] --;
            }
        }

        int res = n + 1, cur = 0;
        for (int i = 0; i <= n; i ++) {
            cur += diff[i];
            if (cur) res += 2;
            diff[i] = 0;
        }

        if (res > t) r = mid - 1;
        else l = mid + 1;
    }

    cout << r;

    return 0;
}