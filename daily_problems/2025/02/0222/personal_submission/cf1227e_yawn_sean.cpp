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
    for (auto &s: grid)
        cin >> s;
    
    vector<vector<int>> acc(n + 1, vector<int>(m + 1, 0)), ngrid(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == 'X') {
                acc[i + 1][j + 1] = 1;
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= m; j ++) {
            acc[i + 1][j] += acc[i][j];
        }
    }

    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j < m; j ++) {
            acc[i][j + 1] += acc[i][j];
        }
    }

    int l = 0, r = (min(n, m) - 1) / 2;

    auto check = [&] (int i, int j, int r) -> bool {
        return acc[i + r + 1][j + r + 1] - acc[i + r + 1][j - r] - acc[i - r][j + r + 1] + acc[i - r][j - r] == (2 * r + 1) * (2 * r + 1);
    };

    while (l <= r) {
        int mid = (l + r) / 2;

        for (int i = mid; i < n - mid; i ++) {
            for (int j = mid; j < m - mid; j ++) {
                if (check(i, j, mid)) {
                    ngrid[i - mid][j - mid] += 1;
                    ngrid[i - mid][j + mid + 1] -= 1;
                    ngrid[i + mid + 1][j - mid] -= 1;
                    ngrid[i + mid + 1][j + mid + 1] += 1;
                }
            }
        }

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= m; j ++) {
                ngrid[i + 1][j] += ngrid[i][j];
            }
        }

        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j < m; j ++) {
                ngrid[i][j + 1] += ngrid[i][j];
            }
        }

        bool flg = true;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                flg = flg && ((grid[i][j] == 'X') == (ngrid[i][j] > 0));
                ngrid[i][j] = 0;
            }
        }

        if (flg) l = mid + 1;
        else r = mid - 1;
    }

    cout << r << '\n';
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << (i >= r && i < n - r && j >= r && j < m - r && check(i, j, r) ? 'X' : '.');
        }
        cout << '\n';
    }

    return 0;
}