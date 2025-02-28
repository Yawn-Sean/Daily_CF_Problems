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

    vector<vector<int>> grid(n, vector<int>(m));
    vector<string> ops;

    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j ++) {
            grid[i][j] = (s[j] == '.');
            if (grid[i][j]) {
                ops.emplace_back("B " + to_string(i + 1) + ' ' + to_string(j + 1));
            }
        }
    }

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<pair<int, int>> reds;

    auto dfs = [&] (auto &self, int x, int y) -> void {
        for (auto &[dx, dy]: dirs) {
            if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m && grid[x + dx][y + dy]) {
                grid[x + dx][y + dy] = 0;
                reds.emplace_back(x + dx, y + dy);
                self(self, x + dx, y + dy);
            }
        }
    };

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j]) {
                grid[i][j] = 0;
                dfs(dfs, i, j);
            }
        }
    }

    reverse(reds.begin(), reds.end());
    for (auto &[x, y]: reds) {
        ops.emplace_back("D " + to_string(x + 1) + ' ' + to_string(y + 1));
        ops.emplace_back("R " + to_string(x + 1) + ' ' + to_string(y + 1));
    }

    cout << ops.size() << '\n';
    for (auto &x: ops)
        cout << x << '\n';

    return 0;
}