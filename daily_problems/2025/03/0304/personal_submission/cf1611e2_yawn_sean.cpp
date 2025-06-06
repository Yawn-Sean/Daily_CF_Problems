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

    int t;
    cin >> t;

    while (t --) {
        int n, k;
        cin >> n >> k;

        vector<int> nums(k);
        for (auto &v: nums)
            cin >> v;

        vector<vector<int>> path(n + 1);
        for (int i = 0; i < n - 1; i ++) {
            int u, v;
            cin >> u >> v;
            path[u].emplace_back(v);
            path[v].emplace_back(u);
        }

        vector<int> note(n + 1), cur_path;

        auto dfs = [&] (auto &self, int u, int p) -> void {
            cur_path.emplace_back(u);
            note[u] = cur_path[cur_path.size() / 2];

            for (auto &v: path[u]) {
                if (v != p) {
                    self(self, v, u);
                }
            }

            cur_path.pop_back();
        };

        dfs(dfs, 1, 0);

        vector<int> control(n + 1, 0);
        for (auto &v: nums)
            control[note[v]] = 1;
        
        int cnt = 0;

        auto dfs1 = [&] (auto &self, int u, int p) -> void {
            if (control[u]) {
                cnt ++;
                return ;
            }
            if (u != 1 && path[u].size() == 1) cnt = n + 1;
            for (auto &v: path[u]) {
                if (v != p) {
                    self(self, v, u);
                }
            }
        };

        dfs1(dfs1, 1, 0);

        cout << (cnt <= k ? cnt : -1) << '\n';
    }

    return 0;
}