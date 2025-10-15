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

    vector<int> us, vs;
    vector<vector<int>> path(n);
    
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        us.emplace_back(u);
        vs.emplace_back(v);
        path[u].emplace_back(i);
        path[v].emplace_back(i);
    }

    vector<int> col(n - 1, -1);

    auto dfs = [&] (auto &self, int u) -> void {
        int used = -1;
        for (auto &eid: path[u]) {
            if (col[eid] != -1) {
                used = col[eid];
            }
        }

        int cur = 0;
        for (auto &eid: path[u]) {
            if (col[eid] == -1) {
                while (cur == used)
                    cur ++;
                col[eid] = cur;
                cur ++;
                self(self, us[eid] + vs[eid] - u);
            }
        }
    };

    dfs(dfs, 0);

    int ans = *max_element(col.begin(), col.end()) + 1;

    vector<vector<int>> tmp(ans);
    for (int i = 0; i < n - 1; i ++)
        tmp[col[i]].emplace_back(i);
    
    cout << ans << '\n';
    for (int i = 0; i < ans; i ++) {
        cout << tmp[i].size() << ' ';
        for (auto &x: tmp[i]) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}