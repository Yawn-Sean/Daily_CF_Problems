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

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    int sx, sy, tx, ty;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == 'S')
                sx = i, sy = j;
            if (grid[i][j] == 'T')
                tx = i, ty = j;
        }
    }

    auto check = [&] (int x1, int y1, int x2, int y2) -> bool {
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        for (int i = x1; i <= x2; i ++) {
            for (int j = y1; j <= y2; j ++) {
                if (grid[i][j] == '*') {
                    return false;
                }
            }
        }
        return true;
    };

    for (int i = 0; i < n; i ++) {
        if (check(sx, sy, i, sy) && check(i, sy, i, ty) && check(i, ty, tx, ty)) {
            return cout << "YES", 0;
        }
    }

    for (int i = 0; i < m; i ++) {
        if (check(sx, sy, sx, i) && check(sx, i, tx, i) && check(tx, i, tx, ty)) {
            return cout << "YES", 0;
        }
    }
    cout << "NO";

    return 0;
}