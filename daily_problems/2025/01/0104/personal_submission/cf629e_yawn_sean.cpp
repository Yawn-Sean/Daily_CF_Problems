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

    vector<int> depth(n, 0), parent(n, -1), sz(n, 1);
    vector<long long> dp(n, 0);

    auto dfs1 = [&] (auto &self, int u, int p) -> void {
        for (auto &v: path[u]) {
            if (v != p) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                self(self, v, u);
                sz[u] += sz[v];
                dp[u] += dp[v] + sz[v];
            }
        }
    };

    dfs1(dfs1, 0, -1);

    vector<long long> up_dp(n, 0);

    auto dfs2 = [&] (auto &self, int u, int p) -> void {
        for (auto &v: path[u]) {
            if (v != p) {
                up_dp[v] = up_dp[u] + n - sz[v] + (dp[u] - dp[v] - sz[v]);
                self(self, v, u);
            }
        }
    };

    dfs2(dfs2, 0, -1);

    vector<vector<int>> nth_parent(20, vector<int>(n, -1));
    for (int i = 0; i < n; i ++)
        nth_parent[0][i] = parent[i];
    
    for (int i = 0; i < 19; i ++) {
        for (int j = 0; j < n; j ++) {
            if (nth_parent[i][j] != -1) {
                nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]];
            }
        }
    }

    auto climb = [&] (int k, int u) -> int {
        while (k) {
            int bit = 31 - __builtin_clz(k & -k);
            u = nth_parent[bit][u];
            k -= k & -k;
        }
        return u;
    };

    auto lca = [&] (int u, int v) -> int {
        if (depth[u] > depth[v])
            swap(u, v);
        
        v = climb(depth[v] - depth[u], v);
        if (u == v) return u;

        for (int i = 19; i >= 0; i --) {
            if (nth_parent[i][u] != nth_parent[i][v]) {
                u = nth_parent[i][u];
                v = nth_parent[i][v];
            }
        }

        return nth_parent[0][u];
    };

    cout << fixed << setprecision(20);

    while (q --) {
        int u, v;
        cin >> u >> v;
        u --, v --;

        if (depth[u] > depth[v])
            swap(u, v);
        
        int l = lca(u, v), d = depth[u] + depth[v] - 2 * depth[l];
        if (l == u) {
            int tmp = climb(d - 1, v);
            cout << (long double)1.0 * up_dp[tmp] / (n - sz[tmp]) + (long double)1.0 * dp[v] / sz[v] + d << '\n';
        }
        else
            cout << (long double)1.0 * dp[u] / sz[u] + (long double)1.0 * dp[v] / sz[v] + d + 1 << '\n';
    }

    return 0;
}