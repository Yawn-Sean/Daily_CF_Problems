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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;

        for (int j = 1; j <= m; j ++)
            grid[i][j] = s[j - 1] - '0';
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= m; j ++) {
            grid[i + 1][j] += grid[i][j];
        }
    }

    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j < m; j ++) {
            grid[i][j + 1] += grid[i][j];
        }
    }

    auto f = [&] (int i1, int i2, int j1, int j2) {
        return ((i1 * n + i2) * m + j1) * m + j2;
    };

    vector<int> pref(n * n * m * m, 0);

    for (int i1 = 0; i1 < n; i1 ++) {
        for (int i2 = i1; i2 < n; i2 ++) {
            for (int j1 = 0; j1 < m; j1 ++) {
                for (int j2 = j1; j2 < m; j2 ++) {
                    if (grid[i2 + 1][j2 + 1] - grid[i2 + 1][j1] - grid[i1][j2 + 1] + grid[i1][j1] == 0)
                        pref[f(n - 1 - i1, i2, m - 1 - j1, j2)] = 1;
                }
            }
        }
    }

    for (int i1 = 0; i1 < n - 1; i1 ++) {
        for (int i2 = 0; i2 < n; i2 ++) {
            for (int j1 = 0; j1 < m; j1 ++) {
                for (int j2 = 0; j2 < m; j2 ++) {
                    pref[f(i1 + 1, i2, j1, j2)] += pref[f(i1, i2, j1, j2)];
                }
            }
        }
    }

    for (int i1 = 0; i1 < n; i1 ++) {
        for (int i2 = 0; i2 < n - 1; i2 ++) {
            for (int j1 = 0; j1 < m; j1 ++) {
                for (int j2 = 0; j2 < m; j2 ++) {
                    pref[f(i1, i2 + 1, j1, j2)] += pref[f(i1, i2, j1, j2)];
                }
            }
        }
    }

    for (int i1 = 0; i1 < n; i1 ++) {
        for (int i2 = 0; i2 < n; i2 ++) {
            for (int j1 = 0; j1 < m - 1; j1 ++) {
                for (int j2 = 0; j2 < m; j2 ++) {
                    pref[f(i1, i2, j1 + 1, j2)] += pref[f(i1, i2, j1, j2)];
                }
            }
        }
    }

    for (int i1 = 0; i1 < n; i1 ++) {
        for (int i2 = 0; i2 < n; i2 ++) {
            for (int j1 = 0; j1 < m; j1 ++) {
                for (int j2 = 0; j2 < m - 1; j2 ++) {
                    pref[f(i1, i2, j1, j2 + 1)] += pref[f(i1, i2, j1, j2)];
                }
            }
        }
    }

    while (q --) {
        int i1, i2, j1, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << pref[f(n - i1, i2 - 1, m - j1, j2 - 1)] << '\n';
    }

    return 0;
}