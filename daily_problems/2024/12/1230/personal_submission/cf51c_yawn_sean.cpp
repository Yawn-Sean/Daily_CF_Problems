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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    sort(nums.begin(), nums.end());

    auto div2 = [&] (int x) -> string {
        if (x & 1) return to_string(x / 2) + ".500000";
        return to_string(x / 2) + ".000000";
    };

    if (n < 3) {
        cout << div2(0) << '\n';
        cout << div2(nums[0] * 2) << ' ' << div2(nums.back() * 2) << ' ' << div2(0);
    }
    else {
        int l = 0, r = n - 1;
        int cur = nums[r - 1] - nums[l + 1], idx = l + 1;

        while (l < r) {
            if (nums[l + 1] - nums[0] < nums.back() - nums[r - 1]) l ++;
            else r --;
            int v = max(nums[l] - nums[0], max(nums.back() - nums[r], nums[r - 1] - nums[l + 1]));
            if (v < cur) cur = v, idx = l + 1;
        }

        cout << div2(cur) << '\n';
        cout << div2(nums[0] * 2 + cur) << ' ' << div2(nums[idx] * 2 + cur) << ' ' << div2(nums.back() * 2 - cur);
    }

    return 0;
}