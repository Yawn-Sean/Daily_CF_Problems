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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums)
        cin >> x;

    vector<vector<pair<int, int>>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v, c;
        cin >> u >> v >> c;
        u --, v --;
        path[u].emplace_back(v, c);
        path[v].emplace_back(u, c);
    }

    vector<pair<int, int>> parent(n);

    auto dfs = [&] (auto &self, int u, int p) -> void {
        for (auto &[v, c]: path[u]) {
            if (v != p) {
                parent[v] = {u, c};
                self(self, v, u);
            }
        }
    };

    dfs(dfs, 0, -1);

    vector<vector<int>> cnt(n, vector<int>(n + 1, 0));

    vector<int> order(n), ans(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {return nums[i] < nums[j];});

    for (auto &i: order) {
        int u = i, t = 0;
        while (u) {
            auto [p, c] = parent[u];
            while (cnt[u][t] == c) t ++;
            cnt[u][t] ++, u = p, t ++;
        }
        ans[i] = t;
    }

    for (auto &x: ans) cout << x << ' ';

    return 0;
}