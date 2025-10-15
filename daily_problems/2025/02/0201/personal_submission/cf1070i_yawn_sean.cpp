#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
#include "atcoder/maxflow"
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

    int t;
    cin >> t;

    while (t --) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> path(n);
        atcoder::mf_graph<int> mf(n + m + 2);
        int src = n + m, dst = n + m + 1;

        for (int i = 0; i < m; i ++) {
            int u, v;
            cin >> u >> v;
            u --, v --;
            path[u].emplace_back(i);
            path[v].emplace_back(i);
            mf.add_edge(n + i, dst, 1);
        }

        int total_f = 0;
        for (int i = 0; i < n; i ++) {
            int f = 2 * max(0, (int)path[i].size() - k);
            total_f += f;
            mf.add_edge(src, i, f);
            for (auto &j: path[i]) mf.add_edge(i, n + j, 1);
        }

        if (mf.flow(src, dst) < total_f) {
            for (int i = 0; i < m; i ++)
                cout << "0 ";
        }
        else {
            vector<int> to_pair(n, -1);
            vector<int> ans(m);
            iota(ans.begin(), ans.end(), 0);
            
            for (auto &e: mf.edges()) {
                if (e.flow && e.from < n) {
                    int u = e.to - n;
                    if (to_pair[e.from] != -1) {
                        ans[u] = to_pair[e.from];
                        to_pair[e.from] = -1;
                    }
                    else to_pair[e.from] = e.to - n;
                }
            }

            for (auto &x: ans) cout << x + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}