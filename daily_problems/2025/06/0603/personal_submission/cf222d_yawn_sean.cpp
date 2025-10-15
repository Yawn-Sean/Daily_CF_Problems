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
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> v1(n), v2(n);
    for (auto &x: v1) cin >> x;
    for (auto &x: v2) cin >> x;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans = 0, pt = 0;

    for (int i = n - 1; i >= 0; i --) {
        while (pt < n && v1[i] + v2[pt] < x)
            pt ++;
        if (pt == n) break;
        ans ++, pt ++;
    }

    cout << 1 << ' ' << ans;

    return 0;
}