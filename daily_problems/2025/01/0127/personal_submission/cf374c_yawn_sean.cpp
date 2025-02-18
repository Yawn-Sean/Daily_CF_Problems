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

    map<char, int> mp;
    mp['D'] = 0, mp['I'] = 1, mp['M'] = 2, mp['A'] = 3;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j ++)
            grid[i][j] = mp[s[j]];
    }

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> path(n * m);

    auto f = [&] (int i, int j) {return i * m + j;};

    vector<int> invs(n * m);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            for (auto &[di, dj]: dirs) {
                if (i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m && (grid[i + di][j + dj] - grid[i][j] + 4) % 4 == 1) {
                    path[f(i, j)].emplace_back(f(i + di, j + dj));
                    invs[f(i + di, j + dj)] ++;
                }
            }
        }
    }

    vector<int> stk, ans(n * m, -1);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (invs[f(i, j)] == 0) {
                stk.emplace_back(f(i, j));
                ans[f(i, j)] = grid[i][j];
                if (ans[f(i, j)] == 0) ans[f(i, j)] = 4;
            }
        }
    }

    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();
        for (auto &v: path[u]) {
            invs[v] --;
            ans[v] = max(ans[v], ans[u] + 1);
            if (invs[v] == 0) stk.emplace_back(v);
        }
    }

    if (*max_element(invs.begin(), invs.end()) > 0) cout << "Poor Inna!";
    else {
        int res = (*max_element(ans.begin(), ans.end()) - 3) / 4;
        cout << (res > 0 ? to_string(res) : "Poor Dima!");
    }

    return 0;
}