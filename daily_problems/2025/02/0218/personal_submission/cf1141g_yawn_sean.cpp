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

    int n, k;
    cin >> n >> k;

    vector<int> us(n - 1), vs(n - 1), deg(n);
    vector<vector<int>> path(n);

    for (int i = 0; i < n - 1; i ++) {
        cin >> us[i] >> vs[i];
        us[i] --, vs[i] --;
        deg[us[i]] ++, deg[vs[i]] ++;
        path[us[i]].emplace_back(i);
        path[vs[i]].emplace_back(i);
    }

    sort(deg.begin(), deg.end());
    int ans = deg[n - 1 - k];

    vector<int> col(n - 1, 0);

    auto dfs = [&] (auto &self, int u, int c) -> void {
        int cur = 1;
        for (auto &eid: path[u]) {
            if (!col[eid]) {
                if (path[u].size() > ans) col[eid] = 1;
                else {
                    if (cur == c) cur ++;
                    col[eid] = cur;
                    cur ++;
                }
                self(self, us[eid] + vs[eid] - u, col[eid]);
            }
        }
    };

    dfs(dfs, 0, 0);

    cout << ans << '\n';
    for (auto &x: col) cout << x << ' ';

    return 0;
}