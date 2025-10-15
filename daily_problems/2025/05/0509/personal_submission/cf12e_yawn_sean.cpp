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

    vector<vector<int>> grid(n, vector<int>(n, 0));

    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n - 1; j ++) {
            grid[i][j] = (i + j) % (n - 1) + 1;
        }
    }

    for (int i = 0; i < n; i ++) {
        grid[n - 1][i] = grid[i][i];
        grid[i][n - 1] = grid[i][i];
        grid[i][i] = 0;
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}