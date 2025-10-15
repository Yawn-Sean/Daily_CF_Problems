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

    int n, l, x, y;
    cin >> n >> l >> x >> y;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;

    auto check = [&] (int v) -> vector<int> {
        vector<int> res;
        int pt = 0;
        for (int l = 0; l < n; l ++) {
            while (pt < n && nums[pt] - nums[l] < v)
                pt ++;
            if (pt == n) break;
            if (nums[pt] - nums[l] == v)
                res.emplace_back(nums[l]);
        }
        return res;
    };

    auto vx = check(x), vy = check(y);

    if (vx.size() && vy.size()) return cout << 0, 0;
    else if (vx.size()) return cout << "1\n" << y, 0;
    else if (vy.size()) return cout << "1\n" << x, 0;
    else {
        auto tmp = check(x + y);
        if (tmp.size()) return cout << "1\n" << tmp[0] + x, 0;

        for (auto &v: check(y - x)) {
            if (v - x >= 0) return cout << "1\n" << v - x, 0;
            if (v + y <= l) return cout << "1\n" << v + y, 0;
        }

        cout << "2\n" << x << ' ' << y << '\n';
    }

    return 0;
}