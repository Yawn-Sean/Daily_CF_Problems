#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j ++) {
            grid[i][j] = (s[j] == '*');
        }
    }

    vector<vector<int>> ans(n, vector<int>(m, -1)), nans(n, vector<int>(m, -1));
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < m - 1; j ++) {
            ans[i][j] = 0;
            for (int di = 0; di < 2; di ++) {
                for (int dj = 0; dj < 2; dj ++) {
                    ans[i][j] *= 2;
                    ans[i][j] += grid[i + di][j + dj];
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i < 8; i ++) {
        int sz = 1 << i;

        for (int i = 0; i <= n - sz * 2; i ++) {
            for (int j = 0; j <= m - sz * 2; j ++) {
                int msk = 0; 
                for (int di = 0; di < 2; di ++) {
                    for (int dj = 0; dj < 2; dj ++) {
                        msk *= 2;
                        msk += (ans[i + di * sz][j + dj * sz] == 15);
                    }
                }

                bool flg = true;
                for (int di = 0; di < 2; di ++) {
                    for (int dj = 0; dj < 2; dj ++) {
                        if (ans[i + di * sz][j + dj * sz] != 15 && ans[i + di * sz][j + dj * sz] != msk) flg = false;
                    }
                }
                if (flg) nans[i][j] = msk;
            }
        }

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                ans[i][j] = nans[i][j];
                nans[i][j] = -1;
                if (ans[i][j] != -1) res ++;
            }
        }
    }
    cout << res;

    return 0;
}