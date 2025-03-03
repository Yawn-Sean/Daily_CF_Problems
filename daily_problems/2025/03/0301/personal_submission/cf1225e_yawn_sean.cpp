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

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    if (grid[0][0] == 'R' || grid[n - 1][m - 1] == 'R') return cout << 0, 0;
    if (n == 1 && m == 1) return cout << 1, 0;

    vector<vector<int>> acc_h(n, vector<int>(m + 1, 0)), acc_v(n + 1, vector<int>(m, 0));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == 'R') {
                acc_h[i][j] = 1;
                acc_v[i][j] = 1;
            }
        }
    }

    for (int i = n - 2; i >= 0; i --) {
        for (int j = 0; j < m; j ++) {
            acc_v[i][j] += acc_v[i + 1][j];
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = m - 2; j >= 0; j --) {
            acc_h[i][j] += acc_h[i][j + 1];
        }
    }

    int mod = 1e9 + 7;

    vector<vector<int>> diff_h(n, vector<int>(m + 1, 0)), diff_v(n + 1, vector<int>(m, 0));
    vector<int> cur_h(n, 0), cur_v(m, 0);

    diff_h[0][0] = 1, diff_h[0][1] = mod - 1;
    diff_v[0][0] = 1, diff_v[1][0] = mod - 1;

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    auto minus = [&] (int &x, int y) -> void {
        x -= y;
        if (x < 0) x += mod;
    };

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            add(cur_h[i], diff_h[i][j]);
            add(cur_v[j], diff_v[i][j]);
            
            add(diff_h[i][j + 1], cur_v[j]);
            minus(diff_h[i][m - acc_h[i][j + 1]], cur_v[j]);

            add(diff_v[i + 1][j], cur_h[i]);
            minus(diff_v[n - acc_v[i + 1][j]][j], cur_h[i]);
        }
    }

    add(cur_h[n - 1], cur_v[m - 1]);
    cout << cur_h[n - 1];

    return 0;
}