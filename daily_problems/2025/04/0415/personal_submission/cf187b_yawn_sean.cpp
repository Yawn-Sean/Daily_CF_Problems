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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!

int dis[60][60][60];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    memset(dis, 0x3f, sizeof(dis));

    while (m --) {
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                for (int k = 0; k < n; k ++) {
                    grid[j][k] = min(grid[j][k], grid[j][i] + grid[i][k]);
                }
            }
        }

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                dis[0][i][j] = min(dis[0][i][j], grid[i][j]);
            }
        }
    }

    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            for (int k = 0; k < n; k ++) {
                for (int nk = 0; nk < n; nk ++) {
                    dis[i][j][nk] = min(dis[i][j][nk], dis[i - 1][j][k] + dis[0][k][nk]);
                }
            }
        }
    }

    while (q --) {
        int u, v, k;
        cin >> u >> v >> k;
        u --, v --;
        cout << dis[min(k, n - 1)][u][v] << '\n';
    }

    return 0;
}