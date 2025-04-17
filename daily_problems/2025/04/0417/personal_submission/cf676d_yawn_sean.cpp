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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<char, int> d;
    d['+'] = 0;
    d['-'] = 1;
    d['|'] = 2;
    d['^'] = 3;
    d['>'] = 4;
    d['v'] = 5;
    d['<'] = 6;
    d['U'] = 7;
    d['R'] = 8;
    d['D'] = 9;
    d['L'] = 10;
    d['*'] = 11;
 
    vector<int> rotate = {0, 2, 1, 4, 5, 6, 3, 8, 9, 10, 7, 11};
    vector<vector<int>> moves(4, vector<int>(12));

    iota(moves[0].begin(), moves[0].end(), 0);
    for (int i = 1; i < 4; i ++) {
        for (int j = 0; j < 12; j ++) {
            moves[i][j] = rotate[moves[i - 1][j]];
        }
    }

    vector<pair<int, int>> tmp = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<int> dirs = {15, 10, 5, 1, 2, 4, 8, 14, 13, 11, 7, 0};

    vector<vector<int>> bits(16);
    for (int i = 0; i < 16; i ++) {
        for (int j = 0; j < 4; j ++) {
            if (i >> j & 1) bits[i].emplace_back(j);
        }
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j ++)
            grid[i][j] = d[s[j]];
    }

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    sx --, sy --, tx --, ty --;

    vector<vector<int>> dis(4, vector<int>(n * m, -1));

    auto f = [&] (int x, int y) -> int {return x * m + y;};

    queue<pair<int, int>> q;

    q.push({f(sx, sy), 0});
    dis[0][f(sx, sy)] = 0;

    while (!q.empty()) {
        auto [msk, status] = q.front();
        q.pop();
        int x = msk / m, y = msk % m;

        if (x == tx && y == ty)
            return cout << dis[status][msk], 0;
        
        for (auto &bit: bits[dirs[moves[status][grid[x][y]]]]) {
            auto [dx, dy] = tmp[bit];
            int nx = x + dx, ny = y + dy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dis[status][f(nx, ny)] == -1 && dirs[moves[status][grid[nx][ny]]] >> (bit ^ 2) & 1) {
                dis[status][f(nx, ny)] = dis[status][f(x, y)] + 1;
                q.push({f(nx, ny), status});
            }
        }

        int nstatus = (status + 1) & 3;
        if (dis[nstatus][f(x, y)] == -1) {
            dis[nstatus][f(x, y)] = dis[status][f(x, y)] + 1;
            q.push({f(x, y), nstatus});
        }
    }

    cout << -1;

    return 0;
}