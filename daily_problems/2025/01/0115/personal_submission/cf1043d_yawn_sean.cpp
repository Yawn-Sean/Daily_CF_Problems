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

    vector<vector<int>> ars(m, vector<int>(n)), pos(m, vector<int>(n + 1));
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> ars[i][j];
            pos[i][ars[i][j]] = j;
        }
    }

    long long ans = 0;
    int l = 0;

    while (l < n) {
        int r = l;
        while (r + 1 < n) {
            bool flg = true;
            for (int i = 1; i < m; i ++) {
                if (pos[i][ars[0][r + 1]] - pos[i][ars[0][r]] != 1) {
                    flg = false;
                }
            }
            if (!flg) break;
            r ++;
        }
        ans += 1ll * (r - l + 1) * (r - l + 2) / 2;
        l = r + 1;
    }

    cout << ans;

    return 0;
}