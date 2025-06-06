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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> grid[i][j];
        }
    }

    bool flg = true;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[0][0] + grid[i][j] != grid[i][0] + grid[0][j]) {
                flg = false;
            }
        }
    }

    if (!flg) return cout << -1, 0;
    else {
        int v = grid[0][0];
        if (n < m) v = *min_element(grid[0].begin(), grid[0].end());
        else {
            for (int i = 0; i < n; i ++) v = min(v, grid[i][0]);
            v = grid[0][0] - v;
        }

        vector<pair<int, int>> rows, cols;

        int total = grid[0][0];
        rows.emplace_back(1, v);
        cols.emplace_back(1, grid[0][0] - v);

        for (int i = 1; i < n; i ++) {
            total += grid[i][0] - (grid[0][0] - v);
            rows.emplace_back(i + 1, grid[i][0] - (grid[0][0] - v));
        }
        
        for (int i = 1; i < m; i ++) {
            total += grid[0][i] - v;
            cols.emplace_back(i + 1, grid[0][i] - v);
        }
        
        cout << total << '\n';

        for (auto &[k, v]: rows) {
            for (int i = 0; i < v; i ++) {
                cout << "row " << k << '\n';
            }
        }

        for (auto &[k, v]: cols) {
            for (int i = 0; i < v; i ++) {
                cout << "col " << k << '\n';
            }
        }
    }

    return 0;
}