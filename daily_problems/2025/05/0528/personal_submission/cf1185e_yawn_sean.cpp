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

    int t;
    cin >> t;

    while (t --) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (auto &s: grid) cin >> s;

        vector<int> x_min(26, n), x_max(26, -1), y_min(26, m), y_max(26, -1);

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] > '.') {
                    int c = grid[i][j] - 'a';

                    x_min[c] = min(x_min[c], i);
                    x_max[c] = max(x_max[c], i);
                    
                    y_min[c] = min(y_min[c], j);
                    y_max[c] = max(y_max[c], j);
                }
            }
        }

        vector<array<int, 4>> ops;
        int xl = n, xr = -1, yl = m, yr = -1;

        bool flg = true;

        for (int i = 25; i >= 0; i --) {
            if (x_min[i] <= x_max[i]) {
                if (x_min[i] == x_max[i] || y_min[i] == y_max[i]) {
                    xl = x_min[i], xr = x_max[i];
                    yl = y_min[i], yr = y_max[i];
                }
                else {
                    flg = false;
                    break;
                }
            }
            if (xl != n) ops.push_back({xl, xr, yl, yr});
        }

        if (!flg) {
            cout << "NO\n";
            continue;
        }

        vector<string> tmp_grid(n, string(m, '.'));

        int k = ops.size();
        reverse(ops.begin(), ops.end());

        for (int i = 0; i < k; i ++) {
            auto [vxl, vxr, vyl, vyr] = ops[i];
            for (int x = vxl; x <= vxr; x ++) {
                for (int y = vyl; y <= vyr; y ++) {
                    tmp_grid[x][y] = 'a' + i;
                }
            }
        }

        for (int i = 0; i < n; i ++)
            if (grid[i] != tmp_grid[i])
                flg = false;
        
        if (flg) {
            cout << "YES\n";
            cout << k << '\n';
            for (auto &[vxl, vxr, vyl, vyr]: ops)
                cout << vxl + 1 << ' ' << vyl + 1 << ' ' << vxr + 1 << ' ' << vyr + 1 << '\n';
        }
        else cout << "NO\n";
    }

    return 0;
}