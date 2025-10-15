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

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> path(n);

    for (int i = 0; i < m; i ++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        u --, v --;
        path[u].emplace_back(v, c - 'a');
    }

    vector<vector<int>> saved(26, vector<int>(n * n, -1));

    auto dfs = [&] (auto &self, int u, int v, int c) -> void {
        if (saved[c][u * n + v] != -1) return ;
        saved[c][u * n + v] = 0;
        for (auto &[nu, nc]: path[u]) {
            if (nc >= c) {
                self(self, v, nu, nc);
                if (saved[nc][v * n + nu] == 0)
                    saved[c][u * n + v] = 1;
            }
        }
    };

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (saved[0][i * n + j] == -1)
                dfs(dfs, i, j, 0);
            cout << (saved[0][i * n + j] ? 'A' : 'B');
        }
        cout << '\n';
    }

    return 0;
}