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

    int n, k;
    cin >> n >> k;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (n == 4 || k <= n) cout << -1;
    else {
        vector<int> tmp;
        for (int i = 1; i <= n; i ++) {
            if (i != a && i != b && i != c && i != d) {
                tmp.emplace_back(i);
            }
        }
        cout << a << ' ' << c << ' ';
        for (auto &x: tmp) cout << x << ' ';
        cout << d << ' ' << b << '\n';

        cout << c << ' ' << a << ' ';
        for (auto &x: tmp) cout << x << ' ';
        cout << b << ' ' << d << '\n';
    }

    return 0;
}