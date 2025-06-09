#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
#include "atcoder/dsu"
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

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    atcoder::dsu uf(n);
    vector<vector<pair<int, int>>> path(n);

    int m;
    cin >> m;

    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;

        if (uf.merge(u, v)) {
            path[u].emplace_back(v, i);
            path[v].emplace_back(u, ~i);
        }
    }

    vector<bool> vis(n, 0);
    vector<int> ans(m, 0); 

    auto dfs = [&] (auto &self, int u, int p) -> void {
        vis[u] = 1;
        for (auto &[v, eid]: path[u]) {
            if (v != p) {
                self(self, v, u);
                if (eid >= 0) ans[eid] = nums[v];
                else ans[~eid] = -nums[v];
                nums[u] += nums[v];
            }
        }
    };

    for (int i = 0; i < n; i ++) {
        if (!vis[i]) {
            dfs(dfs, i, -1);
            if (nums[i]) return cout << "Impossible\n", 0;
        }
    }

    cout << "Possible\n";
    for (auto &x: ans) cout << x << '\n';

    return 0;
}