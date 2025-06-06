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

    int n, k;
    cin >> n >> k;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    vector<vector<int>> acc(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            acc[i + 1][j + 1] = (grid[i][j] == 'X');
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= n; j ++) {
            acc[i + 1][j] += acc[i][j];
        }
    }

    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j < n; j ++) {
            acc[i][j + 1] += acc[i][j];
        }
    }

    vector<vector<int>> group(n, vector<int>(n, -1));
    vector<int> group_cnt(n * n);
    vector<vector<int>> re_calc(n + 1, vector<int>(n + 1, 0));

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    auto f = [&] (int i, int j) -> int {return i * n + j;};

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (grid[i][j] == '.' && group[i][j] == -1) {
                int group_id = f(i, j), sz = 0;
                int mxx = i, mnx = i, mxy = j, mny = j;

                auto dfs = [&] (auto &self, int x, int y) -> void {
                    sz ++;
                    group[x][y] = group_id;
                    mxx = max(mxx, x);
                    mnx = min(mnx, x);
                    mxy = max(mxy, y);
                    mny = min(mny, y);

                    for (auto &[dx, dy]: dirs) {
                        if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < n && group[x + dx][y + dy] == -1 && grid[x + dx][y + dy] == '.')
                            self(self, x + dx, y + dy);
                    }
                };

                dfs(dfs, i, j);

                group_cnt[group_id] = sz;

                if (mxx - mnx < k && mxy - mny < k) {
                    int lx = max(0, mxx - k + 1), rx = min(mnx, n - k);
                    int ly = max(0, mxy - k + 1), ry = min(mny, n - k);

                    re_calc[lx][ly] += sz;
                    re_calc[lx][ry + 1] -= sz;
                    re_calc[rx + 1][ly] -= sz;
                    re_calc[rx + 1][ry + 1] += sz;
                }
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= n; j ++) {
            re_calc[i + 1][j] += re_calc[i][j];
        }
    }

    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j < n; j ++) {
            re_calc[i][j + 1] += re_calc[i][j];
        }
    }

    vector<bool> vis(n * n, 0);
    int ans = 0;

    for (int i = 0; i <= n - k; i ++) {
        for (int j = 0; j <= n - k; j ++) {
            int res = 0;
            vector<int> tmp;

            if (i) {
                for (int nj = j; nj < j + k; nj ++) {
                    if (grid[i - 1][nj] == '.' && !vis[group[i - 1][nj]]) {
                        vis[group[i - 1][nj]] = 1;
                        tmp.emplace_back(group[i - 1][nj]);
                        res += group_cnt[group[i - 1][nj]];
                    }
                }
            }

            if (i + k < n) {
                for (int nj = j; nj < j + k; nj ++) {
                    if (grid[i + k][nj] == '.' && !vis[group[i + k][nj]]) {
                        vis[group[i + k][nj]] = 1;
                        tmp.emplace_back(group[i + k][nj]);
                        res += group_cnt[group[i + k][nj]];
                    }
                }
            }

            if (j) {
                for (int ni = i; ni < i + k; ni ++) {
                    if (grid[ni][j - 1] == '.' && !vis[group[ni][j - 1]]) {
                        vis[group[ni][j - 1]] = 1;
                        tmp.emplace_back(group[ni][j - 1]);
                        res += group_cnt[group[ni][j - 1]];
                    }
                }
            }

            if (j + k < n) {
                for (int ni = i; ni < i + k; ni ++) {
                    if (grid[ni][j + k] == '.' && !vis[group[ni][j + k]]) {
                        vis[group[ni][j + k]] = 1;
                        tmp.emplace_back(group[ni][j + k]);
                        res += group_cnt[group[ni][j + k]];
                    }
                }
            }

            res += acc[i + k][j + k] - acc[i][j + k] - acc[i + k][j] + acc[i][j];
            res += re_calc[i][j];
            ans = max(ans, res);

            for (auto &x: tmp) vis[x] = 0;
        }
    }

    cout << ans;

    return 0;
}