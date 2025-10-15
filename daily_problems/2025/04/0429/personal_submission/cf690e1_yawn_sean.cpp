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

    int t;
    cin >> t;

    while (t --) {
        int h, w;
        cin >> h >> w;

        vector<vector<int>> grid(h, vector<int>(w));
        for (int i = 0; i < h; i ++) {
            for (int j = 0; j < w; j ++) {
                cin >> grid[i][j];
            }
        }

        int res1 = 0, res2 = 0;

        for (int i = 0; i < w; i ++) {
            res1 += abs(grid[0][i] - grid[h - 1][i]);
            res2 += abs(grid[h / 2][i] - grid[h / 2 - 1][i]);
        }

        cout << (res1 > res2 ? "NO" : "YES") << '\n';
    }

    return 0;
}