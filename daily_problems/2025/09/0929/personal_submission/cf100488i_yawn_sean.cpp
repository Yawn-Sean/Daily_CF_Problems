#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, c;
    cin >> n >> m >> c;

    vector<vector<int>> path(n, vector<int>(n, 0));

    while (m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u][v] = 1;
        path[v][u] = 1;
    }

    vector<int> cols(n, 0);
    int col = 1;

    auto dfs = [&] (auto &self, int u) -> void {
        cols[u] = col;

        for (int v = 0; v < n; v ++) {
            if (!path[u][v] && !cols[v]) {
                self(self, v);
            }
        }
    };

    for (int i = 0; i < n; i ++)
        if (!cols[i]) dfs(dfs, i), col ++;

    if (col - 1 > c) return cout << -1, 0;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (path[i][j] == (cols[i] == cols[j])) return cout << -1, 0;
        }
    }

    for (auto &v: cols) cout << v << ' ';

    return 0;
}