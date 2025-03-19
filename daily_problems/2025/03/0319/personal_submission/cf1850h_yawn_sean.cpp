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

    int t;
    cin >> t;

    long long inf = 1e15;

    while (t --) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> path(n + 1);
        for (int i = 0; i < m; i ++) {
            int u, v, w;
            cin >> u >> v >> w;
            path[u].emplace_back(v, w);
            path[v].emplace_back(u, -w);
        }

        vector<long long> cur(n + 1, inf);
        bool flg = true;

        auto dfs = [&] (auto &self, int u) -> void {
            for (auto &[v, w]: path[u]) {
                if (cur[v] == inf) {
                    cur[v] = cur[u] + w;
                    self(self, v);
                }
                else if (cur[v] != cur[u] + w)
                    flg = false;
            }
        };

        for (int i = 0; i <= n; i ++) {
            if (cur[i] == inf) {
                cur[i] = 0;
                dfs(dfs, i);
            }
        }

        cout << (flg ? "YES" : "NO") << '\n';
    }

    return 0;
}