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

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> left(n, vector<int>(m, 0)), right(n, vector<int>(m, 0)), up(n, vector<int>(m, 0)), down(n, vector<int>(m, 0));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j]) {
                left[i][j] = 1;
                right[i][j] = 1;
                up[i][j] = 1;
                down[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j]) {
                if (j) left[i][j] += left[i][j - 1];
                if (i) up[i][j] += up[i - 1][j];
            }
        }
    }

    for (int i = n - 1; i >= 0; i --) {
        for (int j = m - 1; j >= 0; j --) {
            if (grid[i][j]) {
                if (j + 1 < m) right[i][j] += right[i][j + 1];
                if (i + 1 < n) down[i][j] += down[i + 1][j];
            }
        }
    }

    while (q --) {
        int op, x, y;
        cin >> op >> x >> y;
        x --, y --;

        if (op == 1) {
            grid[x][y] ^= 1;

            for (int i = 0; i < m; i ++) {
                if (grid[x][i]) {
                    left[x][i] = 1;
                    if (i) left[x][i] += left[x][i - 1];
                }
                else left[x][i] = 0;
            }

            for (int i = m - 1; i >= 0; i --) {
                if (grid[x][i]) {
                    right[x][i] = 1;
                    if (i + 1 < m) right[x][i] += right[x][i + 1];
                }
                else right[x][i] = 0;
            }

            for (int i = 0; i < n; i ++) {
                if (grid[i][y]) {
                    up[i][y] = 1;
                    if (i) up[i][y] += up[i - 1][y];
                }
                else up[i][y] = 0;
            }

            for (int i = n - 1; i >= 0; i --) {
                if (grid[i][y]) {
                    down[i][y] = 1;
                    if (i + 1 < n) down[i][y] += down[i + 1][y];
                }
                else down[i][y] = 0;
            }
        }
        else {
            int ans = 0, l, r, cur;

            l = x, r = x, cur = left[x][y];

            while (true) {
                ans = max(ans, cur * (r - l + 1));
                if (r - l == n - 1) break;
                if (l == 0)
                    cur = min(cur, left[++r][y]);
                else if (r == n - 1)
                    cur = min(cur, left[--l][y]);
                else if (left[l - 1][y] > left[r + 1][y])
                    cur = min(cur, left[--l][y]);
                else
                    cur = min(cur, left[++r][y]);
            }

            l = x, r = x, cur = right[x][y];

            while (true) {
                ans = max(ans, cur * (r - l + 1));
                if (r - l == n - 1) break;
                if (l == 0)
                    cur = min(cur, right[++r][y]);
                else if (r == n - 1)
                    cur = min(cur, right[--l][y]);
                else if (right[l - 1][y] > right[r + 1][y])
                    cur = min(cur, right[--l][y]);
                else
                    cur = min(cur, right[++r][y]);
            }

            l = y, r = y, cur = up[x][y];

            while (true) {
                ans = max(ans, cur * (r - l + 1));
                if (r - l == m - 1) break;
                if (l == 0)
                    cur = min(cur, up[x][++r]);
                else if (r == m - 1)
                    cur = min(cur, up[x][--l]);
                else if (up[x][l - 1] > up[x][r + 1])
                    cur = min(cur, up[x][--l]);
                else
                    cur = min(cur, up[x][++r]);
            }

            l = y, r = y, cur = down[x][y];

            while (true) {
                ans = max(ans, cur * (r - l + 1));
                if (r - l == m - 1) break;
                if (l == 0)
                    cur = min(cur, down[x][++r]);
                else if (r == m - 1)
                    cur = min(cur, down[x][--l]);
                else if (down[x][l - 1] > down[x][r + 1])
                    cur = min(cur, down[x][--l]);
                else
                    cur = min(cur, down[x][++r]);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}