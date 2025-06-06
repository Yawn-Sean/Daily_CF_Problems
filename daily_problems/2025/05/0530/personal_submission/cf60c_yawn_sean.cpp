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

    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 3>>> path(n);

    for (int i = 0; i < m; i ++) {
        int u, v, g, l;
        cin >> u >> v >> g >> l;

        u --, v --;
        path[u].push_back({v, g, l});
        path[v].push_back({u, g, l});
    }

    vector<long long> ans(n, -1);

    for (int i = 0; i < n; i ++) {
        if (ans[i] == -1) {
            if (path[i].size() == 0) {
                ans[i] = 1;
                continue;
            }

            bool total_flg = false;

            int cur_l = 0;
            for (auto &[u, g, l]: path[i])
                cur_l = gcd(cur_l, l);
            
            for (int x = 1; x <= 1000; x ++) {
                if (cur_l % x == 0) {
                    bool flg;

                    auto dfs = [&] (auto &self, int u) -> void {
                        if (!ans[u]) {
                            flg = false;
                            return;
                        }

                        for (auto &[v, g, l]: path[u]) {
                            if (ans[v] == -1) {
                                ans[v] = 1ll * g * l / ans[u];
                                self(self, v);
                            }
                            if (1ll * ans[v] * ans[u] != 1ll * g * l || gcd(ans[u], ans[v]) != g) {
                                flg = false;
                                break;
                            }
                        }
                    };

                    auto reset = [&] (auto &self, int u) -> void {
                        ans[u] = -1;
                        for (auto &[v, g, l]: path[u]) {
                            if (ans[v] != -1) {
                                ans[v] = -1;
                                self(self, v);
                            }
                        }
                    };

                    flg = true;
                    ans[i] = x;
                    dfs(dfs, i);

                    if (flg) {
                        total_flg = true;
                        break;
                    }

                    reset(reset, i);

                    flg = true;
                    ans[i] = cur_l / x;
                    dfs(dfs, i);

                    if (flg) {
                        total_flg = true;
                        break;
                    }

                    reset(reset, i);
                }
            }
            if (!total_flg) return cout << "NO", 0;
        }
    }
    cout << "YES\n";
    for (auto &x: ans) cout << x << ' ';

    return 0;
}