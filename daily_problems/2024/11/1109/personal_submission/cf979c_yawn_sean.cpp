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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    vector<vector<int>> path(n + 1);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> parent(n + 1), size(n + 1, 1);

    auto dfs = [&] (auto &self, int u, int p) -> void {
        parent[u] = p;
        for (auto &v: path[u]) {
            if (v != p) {
                self(self, v, u);
                size[u] += size[v];
            }
        }
    };

    dfs(dfs, x, -1);

    long long ans = size[y];
    while (parent[y] != x) y = parent[y];
    ans *= n - size[y];

    cout << 1ll * n * (n - 1) - ans;

    return 0;
}