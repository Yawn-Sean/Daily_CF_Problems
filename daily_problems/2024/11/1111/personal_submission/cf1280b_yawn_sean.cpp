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

    int t;
    cin >> t;

    while (t --) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (auto &s: grid) cin >> s;

        bool f0, f1, f2, f4, f5, f;

        f0 = true, f5 = true;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 'A') f5 = false;
                else f0 = false;
            }
        }

        if (f0) cout << "0\n";
        else if (f5) cout << "MORTAL\n";
        else {
            f1 = false;

            f = true;
            for (int i = 0; i < n; i ++) {
                if (grid[i][0] != 'A') {
                    f = false;
                }
            }
            if (f) f1 = true;

            f = true;
            for (int i = 0; i < n; i ++) {
                if (grid[i][m - 1] != 'A') {
                    f = false;
                }
            }
            if (f) f1 = true;

            f = true;
            for (int i = 0; i < m; i ++) {
                if (grid[0][i] != 'A') {
                    f = false;
                }
            }
            if (f) f1 = true;

            f = true;
            for (int i = 0; i < m; i ++) {
                if (grid[n - 1][i] != 'A') {
                    f = false;
                }
            }
            if (f) f1 = true;

            if (f1) cout << "1\n";
            else {
                f2 = false;
                if (grid[0][0] == 'A' || grid[n - 1][0] == 'A' || grid[0][m - 1] == 'A' || grid[n - 1][m - 1] == 'A') f2 = true;
                else {
                    for (int i = 0; i < n; i ++) {
                        f = true;
                        for (int j = 0; j < m; j ++) {
                            if (grid[i][j] != 'A') f = false;
                        }
                        if (f) f2 = true;
                    }
                    for (int j = 0; j < m; j ++) {
                        f = true;
                        for (int i = 0; i < n; i ++) {
                            if (grid[i][j] != 'A') f = false;
                        }
                        if (f) f2 = true;
                    }
                }

                if (f2) cout << "2\n";
                else {
                    f4 = true;
                    for (int i = 0; i < n; i ++) {
                        for (int j = 0; j < m; j ++) {
                            if (grid[i][j] == 'A' && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) f4 = false;
                        }
                    }
                    cout << (f4 ? "4\n" : "3\n");
                }
            }
        }
    }

    return 0;
}