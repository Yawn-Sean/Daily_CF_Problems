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

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> rs(n + m + 1), xs(n + m + 1), ys(n + m + 1);
    rs[0] = 2e9;
    xs[0] = 0;
    ys[0] = 0;

    for (int i = 1; i <= n; i ++) {
        rs[i] = 0;
        cin >> xs[i] >> ys[i];
    }

    for (int i = n + 1; i <= n + m; i ++)
        cin >> rs[i] >> xs[i] >> ys[i];
    
    vector<int> st_range(n + m + 1);
    iota(st_range.begin(), st_range.end(), 0);
    sort(st_range.begin(), st_range.end(), [&] (int i, int j) {return rs[i] > rs[j];});

    vector<vector<int>> nth_parent(13, vector<int>(n + m + 1));
    vector<int> depth(n + m + 1, 0);

    for (int i = 1; i <= n + m; i ++) {
        for (int j = i - 1; j >= 0; j --) {
            int u = st_range[i], v = st_range[j];
            if (1ll * (xs[u] - xs[v]) * (xs[u] - xs[v]) + 1ll * (ys[u] - ys[v]) * (ys[u] - ys[v]) < 1ll * (rs[u] - rs[v]) * (rs[u] - rs[v])) {
                nth_parent[0][u] = v;
                depth[u] = depth[v] + 1;
                break;
            }
        }
    }

    for (int i = 1; i < 13; i ++) {
        for (int j = 0; j <= n + m; j ++) {
            if (nth_parent[i - 1][j] != -1) {
                nth_parent[i][j] = nth_parent[i - 1][nth_parent[i - 1][j]];
            }
        }
    }

    auto lca = [&] (int u, int v) -> int {
        if (depth[u] > depth[v]) swap(u, v);

        int x = depth[v] - depth[u];

        while (x) {
            int bit = 31 - __builtin_clz(x & -x);
            v = nth_parent[bit][v];
            x -= x & -x;
        }

        if (u == v) return u;

        for (int i = 12; i >= 0; i --) {
            if (nth_parent[i][u] != nth_parent[i][v]) {
                u = nth_parent[i][u];
                v = nth_parent[i][v];
            }
        }
        return nth_parent[0][u];
    };

    while (q --) {
        int u, v;
        cin >> u >> v;
        cout << (u == v ? 0 : depth[u] + depth[v] - depth[lca(u, v)] * 2 - 2) << '\n';
    }

    return 0;
}