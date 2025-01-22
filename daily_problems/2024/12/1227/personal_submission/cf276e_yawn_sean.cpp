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

    int n, q;
    cin >> n >> q;

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> vis(n, -1), depth(n, 0), chain_len(n, 0);
    vector<atcoder::fenwick_tree<int>> fens(n);

    vis[0] = 0;

    for (auto &i: path[0]) {
        vis[i] = i;
        depth[i] = 1;

        int u = i;
        while (path[u].size() != 1) {
            int v = (vis[path[u][0]] == -1 ? path[u][0] : path[u][1]);
            depth[v] = depth[u] + 1;
            vis[v] = i;
            u = v;
        }

        fens[i] = atcoder::fenwick_tree<int>(depth[u]);
        chain_len[i] = depth[u];
    }

    int ans0 = 0;
    atcoder::fenwick_tree<int> total(n);

    while (q --) {
        int t;
        cin >> t;

        if (t) {
            int v;
            cin >> v;
            v --;
            if (v == 0) cout << ans0 << '\n';
            else cout << ans0 + total.sum(0, depth[v]) + fens[vis[v]].sum(0, depth[v]) << '\n';
        }
        else {
            int v, x, d;
            cin >> v >> x >> d;
            v --;
            int chain_id = vis[v];

            cout << d << depth[v] << endl;
            if (d < depth[v]) {
                fens[chain_id].add(depth[v] - d - 1, x);
                if (depth[v] + d < chain_len[chain_id])
                    fens[chain_id].add(depth[v] + d, -x);
            }
            else {
                ans0 += x;
                total.add(d - depth[v], -x);
                cout << d - depth[v] << endl;
                if (v > 0) {
                    fens[chain_id].add(d - depth[v], x);
                    if (depth[v] + d < chain_len[chain_id])
                        fens[chain_id].add(depth[v] + d, -x);
                }
            }
        }
    }

    return 0;
}