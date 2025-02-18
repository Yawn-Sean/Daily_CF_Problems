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

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> path(n);

    while (m --) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        path[u].emplace_back(v, w);
        path[v].emplace_back(u, w);
    }

    vector<int> cols(n, -1);
    bool flg = true;
    int cnt = 0;

    auto dfs = [&] (auto &self, int u) -> void {
        cnt += cols[u];
        for (auto &[v, w]: path[u]) {
            if (cols[v] == -1) {
                cols[v] = cols[u] ^ w ^ 1;
                self(self, v);
            }
            else if ((cols[u] ^ cols[v] ^ w) != 1)
                flg = false;
        }
    };

    for (int i = 0; i < n; i ++) {
        if (cols[i] == -1) {
            cols[i] = 0;
            dfs(dfs, i);
        }
    }

    if (flg) {
        cout << cnt << '\n';
        for (int i = 0; i < n; i ++)
            if (cols[i]) cout << i + 1 << ' ';
    }
    else cout << "Impossible";

    return 0;
}