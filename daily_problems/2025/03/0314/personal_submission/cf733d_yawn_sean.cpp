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

    map<pair<int, int>, pair<int, int>> mp;

    int ans = 0;
    vector<int> chosen = {-1};

    for (int i = 1; i <= n; i ++) {
        vector<int> ar(3);
        for (auto &x: ar) cin >> x;
        sort(ar.begin(), ar.end());

        if (ar[0] >= ans)
            ans = ar[0], chosen = {i};
        
        int a = ar[0], b = ar[1], c = ar[2];

        if (mp.find({a, b}) != mp.end()) {
            auto &[nc, ni] = mp[{a, b}];
            int res = min({a, b, nc + c});
            if (res > ans) {
                ans = res;
                chosen = {ni, i};
            }
        }

        if (mp.find({a, c}) != mp.end()) {
            auto &[nb, ni] = mp[{a, c}];
            int res = min({a, nb + b, c});
            if (res > ans) {
                ans = res;
                chosen = {ni, i};
            }
        }

        if (mp.find({b, c}) != mp.end()) {
            auto &[na, ni] = mp[{b, c}];
            int res = min({na + a, b, c});
            if (res > ans) {
                ans = res;
                chosen = {ni, i};
            }
        }

        mp[{a, b}] = max(mp[{a, b}], {c, i});
        mp[{a, c}] = max(mp[{a, c}], {b, i});
        mp[{b, c}] = max(mp[{b, c}], {a, i});
    }

    cout << chosen.size() << '\n';
    for (auto &x: chosen) cout << x << ' ';

    return 0;
}