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

    int n, m, k, q, inf = 2e9;
    cin >> n >> m >> k >> q;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, inf)), pref(n + 1, vector<int>(m + 1, 0));

    while (q --) {
        int x, y, t;
        cin >> x >> y >> t;
        grid[x][y] = t;
    }

    int l = 0, r = inf;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                pref[i][j] = (grid[i][j] <= mid ? 1 : 0);
            }
        }

        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j < m; j ++) {
                pref[i][j + 1] += pref[i][j];
            }
        }

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= m; j ++) {
                pref[i + 1][j] += pref[i][j];
            }
        }

        bool f = false;

        for (int i = 0; i <= n - k; i ++) {
            for (int j = 0; j <= m - k; j ++) {
                if (pref[i + k][j + k] - pref[i][j + k] - pref[i + k][j] + pref[i][j] == k * k) f = true;
            }
        }

        if (f) r = mid - 1;
        else l = mid + 1;
    }

    cout << (l < inf ? l : -1);

    return 0;
}