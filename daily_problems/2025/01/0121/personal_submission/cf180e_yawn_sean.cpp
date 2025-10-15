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

    int n, m, k;
    cin >> n >> m >> k;

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mp[x].emplace_back(i);
    }

    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        bool flg = false;

        for (auto &[_, v]: mp) {
            int length = v.size();
            for (int i = 0; i + mid - 1 < length; i ++) {
                if (v[i + mid - 1] - v[i] - (mid - 1) <= k) {
                    flg = true;
                }
            }
        }

        if (flg) l = mid + 1;
        else r = mid - 1;
    }

    cout << r;

    return 0;
}