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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q, p;
    cin >> n >> m >> q >> p;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '*') {
                vis[i][j] = -1;
            }
        }
    }

    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                queue<pair<int, int>> que;
                que.push({i, j});
                vis[i][j] = (grid[i][j] - 'A' + 1) * q;
                vector<pair<int, int>> cur;
    
                while (!que.empty()) {
                    auto [x, y] = que.front();
                    que.pop();
                    cur.emplace_back(x, y);
                    ans[x][y] += vis[x][y];
    
                    for (auto &[dx, dy]: dirs) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
                            vis[nx][ny] = vis[x][y] / 2;
                            if (vis[nx][ny]) que.push({nx, ny});
                        }
                    }
                }
    
                for (auto &[x, y]: cur) vis[x][y] = 0;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (ans[i][j] > p) {
                res ++;
            }
        }
    }

    cout << res;

    return 0;
}