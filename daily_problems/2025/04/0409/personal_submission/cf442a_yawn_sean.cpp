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

    int n;
    cin >> n;

    map<char, int> mp;
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    mp['Y'] = 3;
    mp['W'] = 4;

    set<int> nums;
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        nums.insert(mp[s[0]] * 10 + s[1] - '1');
    }

    n = nums.size();

    int ans = 10000;
    for (int msk1 = 0; msk1 < 32; msk1 ++) {
        for (int msk2 = 0; msk2 < 32; msk2 ++) {
            set<int> vis;
            for (auto &x: nums) {
                int cur = 0;
                if (msk1 >> (x / 10) & 1) cur += (x / 10 + 1) * 10;
                if (msk2 >> (x % 10) & 1) cur += x % 10 + 1;
                vis.insert(cur);
            }
            if (vis.size() == n) ans = min(ans, __popcount(msk1) + __popcount(msk2));
        }
    }

    cout << ans;

    return 0;
}