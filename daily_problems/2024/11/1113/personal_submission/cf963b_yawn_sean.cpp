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

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    vector<int> degs(n + 1, 0);
    int rt = 0;

    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if (!x) rt = i;
        else {
            degs[x] ^= 1;
            degs[i] ^= 1;
            tree[x].emplace_back(i);
        }
    }

    if ((n & 1) == 0) return cout << "NO", 0;

    cout << "YES\n";

    vector<int> vis(n + 1, 0);
    auto dfs1 = [&] (auto &self, int u) -> void {
        cout << u << '\n';
        vis[u] = 1;
        for (auto &v: tree[u])
            if (!vis[v]) self(self, v);
    };

    auto dfs2 = [&] (auto &self, int u, int p) -> void {
        for (auto &v: tree[u])
            self(self, v, u);
        if (!degs[u]) {
            if (p != -1) degs[p] ^= 1;
            dfs1(dfs1, u);
        }
    };

    dfs2(dfs2, rt, -1);

    return 0;
}