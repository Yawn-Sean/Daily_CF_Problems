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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> smaller(n, vector<int>(m)), larger(n, vector<int>(m));

    for (int i = 0; i < n; i ++) {
        vector<int> vals;
        for (int j = 0; j < m; j ++)
            vals.emplace_back(grid[i][j]);
        
        sort(vals.begin(), vals.end());
        int k = unique(vals.begin(), vals.end()) - vals.begin();

        for (int j = 0; j < m; j ++) {
            int v = lower_bound(vals.begin(), vals.begin() + k - 1, grid[i][j]) - vals.begin();
            smaller[i][j] = v;
            larger[i][j] = k - 1 - v;
        }
    }

    for (int j = 0; j < m; j ++) {
        vector<int> vals;
        for (int i = 0; i < n; i ++)
            vals.emplace_back(grid[i][j]);
        
        sort(vals.begin(), vals.end());
        int k = unique(vals.begin(), vals.end()) - vals.begin();

        for (int i = 0; i < n; i ++) {
            int v = lower_bound(vals.begin(), vals.begin() + k - 1, grid[i][j]) - vals.begin();
            smaller[i][j] = max(smaller[i][j], v);
            larger[i][j] = max(larger[i][j], k - 1 - v);
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << smaller[i][j] + larger[i][j] + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}