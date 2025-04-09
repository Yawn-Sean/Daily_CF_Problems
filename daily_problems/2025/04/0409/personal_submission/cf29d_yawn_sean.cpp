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

    int k = 0;
    for (int i = 0; i < n; i ++) {
        if (i > 0 && path[i].size() == 1) {
            k ++;
        }
    }

    vector<int> nodes(k), vis(n, n);
    for (int i = 0; i < k; i ++) {
        cin >> nodes[i];
        nodes[i] --;
        vis[nodes[i]] = i;
    }

    auto dp = [&] (auto &self, int u, int p) -> void {
        for (auto &v: path[u]) {
            if (v != p) {
                self(self, v, u);
                vis[u] = min(vis[u], vis[v]);
            }
        }
    };

    dp(dp, 0, -1);

    vector<int> ans;

    auto dfs = [&] (auto &self, int u, int p) -> void {
        sort(path[u].begin(), path[u].end(), [&] (int i, int j) {return vis[i] < vis[j];});
        for (auto &v: path[u]) {
            if (v != p) {
                ans.emplace_back(u);
                self(self, v, u);
            }
        }
        ans.emplace_back(u);
    };

    dfs(dfs, 0, -1);

    int pt = 0;
    for (auto &x: ans) {
        if (pt < k && nodes[pt] == x) {
            pt ++;
        }
    }

    if (pt == k) for (auto &x: ans) cout << x + 1 << ' ';
    else cout << -1;

    return 0;
}