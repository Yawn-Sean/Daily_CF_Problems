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

    int n;
    cin >> n;

    vector<pair<int, int>> pts(n);

    for (auto &[x, y]: pts)
        cin >> x >> y;
    
    long long ans = 1ll * n * (n - 1) / 2 * (n - 2) / 3;

    for (int i = 0; i < n; i ++) {
        map<pair<int, int>, int> mp;

        for (int j = 0; j < i; j ++) {
            int dx = pts[j].first - pts[i].first;
            int dy = pts[j].second - pts[i].second;

            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            if (dx < 0 || (dx == 0 && dy < 0))
                dx = -dx, dy = -dy;
            
            ans -= mp[{dx, dy}];
            mp[{dx, dy}] ++;
        }
    }

    cout << ans;

    return 0;
}