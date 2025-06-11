#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> us(m), vs(m), ws(m);
    vector<vector<int>> path(n);

    for (int i = 0; i < m; i ++) {
        cin >> us[i] >> vs[i] >> ws[i];
        us[i] --, vs[i] --;
        path[us[i]].emplace_back(i);
        path[vs[i]].emplace_back(i);
    }

    vector<int> notes_k(n, 0), notes_b(n, 0), vis(n, 0);
    vector<double> ans(n, 0);

    for (int i = 0; i < n; i ++) {
        if (notes_k[i] == 0) {
            notes_k[i] = 1;

            bool flg = false;
            double val;

            vector<int> vals, eids;
            auto dfs1 = [&] (auto &self, int u) -> void {
                vals.emplace_back(notes_k[u] * notes_b[u]);
                for (auto &eid: path[u]) {
                    eids.emplace_back(eid);
                    int v = us[eid] + vs[eid] - u, w = ws[eid];
                    if (notes_k[v] == 0) {
                        notes_k[v] = -notes_k[u];
                        notes_b[v] = w - notes_b[u];
                        self(self, v);
                    }
                    else if (notes_k[u] == notes_k[v]) {
                        flg = true;
                        val = 1.0 * (w - notes_b[u] - notes_b[v]) / (notes_k[u] + notes_k[v]);
                    }
                }
            };

            dfs1(dfs1, i);

            if (!flg) {
                sort(vals.begin(), vals.end());
                val = -vals[vals.size() / 2];
            }

            ans[i] = val;

            auto dfs2 = [&] (auto &self, int u) -> void {
                for (auto &eid: path[u]) {
                    int v = us[eid] + vs[eid] - u, w = ws[eid];
                    if (!vis[v]) {
                        vis[v] = 1;
                        ans[v] = w - ans[u];
                        self(self, v);
                    }
                }
            };

            dfs2(dfs2, i);

            for (auto &eid: eids) {
                if (abs(ans[us[eid]] + ans[vs[eid]] - ws[eid]) > 0.1) {
                    return cout << "NO", 0;
                }
            }
        }
    }

    cout << "YES\n";
    for (auto &x: ans)
        cout << x << ' ';

    return 0;
}