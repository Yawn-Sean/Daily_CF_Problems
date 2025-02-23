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

    int n;
    cin >> n;

    vector<int> cols(n);
    for (auto &c: cols)
        cin >> c;

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    cout << 1 << ' ';

    auto operate = [&] (int x) -> void {
        cols[x] = -cols[x];
        cout << x + 1 << ' ';
    };

    auto dfs = [&] (auto &self, int u, int p) -> void {
        if (u > 0) operate(u);
        for (auto &v: path[u]) {
            if (v != p) {
                self(self, v, u);
            }
        }
        if (u > 0) operate(p);
        if (cols[u] != 1) {
            if (u > 0) {
                operate(u);
                operate(p);
            }
            else {
                int v = path[u][0];
                operate(v);
                operate(u);
                operate(v);
            }
        }
    };

    dfs(dfs, 0, -1);

    return 0;
}