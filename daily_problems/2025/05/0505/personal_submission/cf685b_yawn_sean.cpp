#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1, 0);
    vector<vector<int>> path(n + 1);

    for (int i = 2; i <= n; i ++) {
        cin >> parent[i];
        path[parent[i]].emplace_back(i);
    }

    vector<int> sz(n + 1, 1);
    
    auto dfs = [&] (auto &self, int u) -> void {
        for (auto &v: path[u]) {
            self(self, v);
            sz[u] += sz[v];
        }
    };

    dfs(dfs, 1);

    vector<int> centroid(n + 1);

    auto dfs1 = [&] (auto &self, int u) -> void {
        int v = -1;
        for (auto &nv: path[u]) {
            self(self, nv);
            if (v == -1 || sz[nv] > sz[v]) {
                v = nv;
            }
        }
        if (v == -1) centroid[u] = u;
        else {
            v = centroid[v];
            while (sz[v] * 2 < sz[u])
                v = parent[v];
            centroid[u] = v;
        }
    };

    dfs1(dfs1, 1);

    while (q --) {
        int u;
        cin >> u;
        cout << centroid[u] << '\n';
    }

    return 0;
}