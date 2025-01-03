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

    if (n <= 4) cout << "No solution";
    else {
        long double angle = acosl(-1) * 2 / n, step = 500, cur = 0, dx = 0.01, x = 0, y = 0;

        cout << fixed << setprecision(8);
        
        for (int i = 1; i < n; i ++) {
            cout << x << ' ' << y << '\n';
            cur += angle;
            step += dx;
            if (i < n - 1) {
                x += step * cosl(cur);
                y += step * sinl(cur);
            }
        }
        cout << x - y / tanl(cur) << ' ' << 0.0;
    }


    return 0;
}