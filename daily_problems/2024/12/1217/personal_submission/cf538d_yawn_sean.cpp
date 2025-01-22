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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (auto &x: grid)
        cin >> x;
    
    vector<string> ans(2 * n - 1, string(2 * n - 1, 'x'));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (grid[i][j] == 'o') {
                for (int ni = 0; ni < n; ni ++) {
                    for (int nj = 0; nj < n; nj ++) {
                        if (grid[ni][nj] == '.') {
                            ans[ni - i + n - 1][nj - j + n - 1] = '.';
                        }
                    }
                }
            }
        }
    }

    ans[n - 1][n - 1] = 'o';

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (grid[i][j] == 'x') {
                bool flg = false;
                for (int di = 0; di < 2 * n - 1; di ++) {
                    for (int dj = 0; dj < 2 * n - 1; dj ++) {
                        if (ans[di][dj] == 'x') {
                            int oi = i - (di - n + 1), oj = j - (dj - n + 1);
                            if (oi >= 0 && oi < n && oj >= 0 && oj < n && grid[oi][oj] == 'o') flg = true;
                        }
                    }
                }
                if (!flg) return cout << "NO", 0;
            }
        }
    }
    cout << "YES\n";
    for (auto &x: ans)
        cout << x << '\n';

    return 0;
}