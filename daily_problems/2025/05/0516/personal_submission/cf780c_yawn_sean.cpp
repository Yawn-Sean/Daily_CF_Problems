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

    int n;
    cin >> n;

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> cols(n);

    auto dfs = [&] (auto &self, int u, int p) -> void {
        int l = path[u].size() + 1;
        vector<bool> vis(l + 1, 0);

        if (cols[u] <= l) vis[cols[u]] = 1;
        if (p >= 0 && cols[p] <= l) vis[cols[p]] = 1;

        int pt = 1;

        for (auto &v: path[u]) {
            if (v != p) {
                while (vis[pt]) pt ++;
                cols[v] = pt, vis[pt] = 1;
                self(self, v, u);
            }
        }
    };

    cols[0] = 1;
    dfs(dfs, 0, -1);

    cout << *max_element(cols.begin(), cols.end()) << '\n';
    for (auto &x: cols) cout << x << ' ';

    return 0;
}