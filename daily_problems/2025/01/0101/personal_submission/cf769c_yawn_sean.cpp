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

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    int sx, sy;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }

    if (k & 1) cout << "IMPOSSIBLE";
    else {
        vector<vector<int>> dis(n, vector<int>(m, -1));
        vector<pair<int, int>> que(n * m);
        que[0] = {sx, sy};
        int l = 0, r = 1;
        dis[sx][sy] = 0;

        string dlru = "DLRU";
        vector<pair<int, int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

        while (l < r) {
            auto [x, y] = que[l];
            l ++;

            for (auto &[dx, dy]: dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*' &&dis[nx][ny] == -1) {
                    dis[nx][ny] = dis[x][y] + 1;
                    que[r] = {nx, ny};
                    r ++;
                }
            }
        }

        while (k) {
            bool flg = false;
            for (int i = 0; i < 4; i ++) {
                auto [dx, dy] = dirs[i];
                int nx = sx + dx, ny = sy + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '*' &&dis[nx][ny] <= k - 1) {
                    sx = nx;
                    sy = ny;
                    cout << dlru[i];
                    flg = true;
                    break;
                    r ++;
                }
            }
            if (!flg) return cout << "IMPOSSIBLE", 0;

            k --;
        }
    }

    return 0;
}