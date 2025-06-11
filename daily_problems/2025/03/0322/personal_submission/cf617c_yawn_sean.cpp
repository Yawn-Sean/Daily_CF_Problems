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

    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    auto d1 = [&] (pair<int, int> pt) -> long long {
        auto [x, y] = pt;
        return 1ll * (x - x1) * (x - x1) + 1ll * (y - y1) * (y - y1);
    };

    auto d2 = [&] (pair<int, int> pt) -> long long {
        auto [x, y] = pt;
        return 1ll * (x - x2) * (x - x2) + 1ll * (y - y2) * (y - y2);
    };

    vector<pair<int, int>> pts(n);
    long long ans = 0;

    for (int i = 0; i < n; i ++) {
        cin >> pts[i].first >> pts[i].second;
        ans = max(ans, d2(pts[i]));
    }

    for (int i = 0; i < n; i ++) {
        long long r1 = d1(pts[i]), r2 = 0;
        
        for (int j = 0; j < n; j ++) {
            if (d1(pts[j]) > r1) {
                r2 = max(r2, d2(pts[j]));
            }
        }

        ans = min(ans, r1 + r2);
    }

    cout << ans;

    return 0;
}