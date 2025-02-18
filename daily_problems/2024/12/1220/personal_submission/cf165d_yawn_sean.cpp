#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
#include "atcoder/fenwicktree"
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

    vector<vector<int>> path(n);
    vector<int> us(n - 1), vs(n - 1);

    for (int i = 0; i < n - 1; i ++) {
        cin >> us[i] >> vs[i];
        us[i] --, vs[i] --;
        path[us[i]].emplace_back(vs[i]);
        path[vs[i]].emplace_back(us[i]);
    }

    vector<int> depth(n, 0), ls(n), rs(n);
    vector<vector<int>> parent(18, vector<int>(n, -1));

    int tmstamp = 0;

    auto dfs = [&] (auto &self, int u, int p) -> void {
        parent[0][u] = p;
        ls[u] = tmstamp ++;
        for (auto &v: path[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                self(self, v, u);
            }
        }
        rs[u] = tmstamp;
    };

    dfs(dfs, 0, -1);

    for (int i = 0; i < 17; i ++) {
        for (int j = 0; j < n; j ++) {
            if (parent[i][j] != -1) {
                parent[i + 1][j] = parent[i][parent[i][j]];
            }
        }
    }

    auto lca = [&] (int u, int v) -> int {
        if (depth[u] > depth[v]) swap(u, v);
        int diff = depth[v] - depth[u];
        while (diff) {
            int x = diff & -diff;
            int bit = 31 - __builtin_clz(x);
            v = parent[bit][v];
            diff -= x;
        }
        if (u == v) return u;
        for (int i = 17; i >= 0; i --) {
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    };

    int q;
    cin >> q;

    atcoder::fenwick_tree<int> fen(n + 1);

    while (q --) {
        int t;
        cin >> t;
        if (t <= 2) {
            int eid;
            cin >> eid;
            eid --;
            int u = (depth[us[eid]] > depth[vs[eid]] ? us[eid] : vs[eid]);
            if (t == 1) {
                fen.add(ls[u], -1);
                fen.add(rs[u], 1);
            }
            else {
                fen.add(ls[u], 1);
                fen.add(rs[u], -1);
            }
        }
        else {
            int u, v;
            cin >> u >> v;
            u --, v --;
            int l = lca(u, v);
            cout << (fen.sum(0, ls[u] + 1) + fen.sum(0, ls[v] + 1) - 2 * fen.sum(0, ls[l] + 1) == 0 ? depth[u] + depth[v] - 2 * depth[l] : -1) << '\n';
        }
    }

    return 0;
}