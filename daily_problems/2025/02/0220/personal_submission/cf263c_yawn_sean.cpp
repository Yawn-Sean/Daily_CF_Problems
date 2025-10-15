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

    int n;
    cin >> n;

    vector<set<int>> path(n + 1);
    for (int i = 0; i < 2 * n; i ++) {
        int u, v;
        cin >> u >> v;
        path[u].insert(v);
        path[v].insert(u);
    }

    if (path[1].size() > 4) return cout << -1, 0;
    else {
        for (auto &u: path[1]) {
            for (auto &v: path[1]) {
                if (u != v) {
                    vector<int> vis(n + 1, 0);
                    vector<int> cycle = {1, u, v};
                    vis[1] = 1, vis[u] = 1, vis[v] = 1;

                    for (int i = 0; i < n - 3; i ++) {
                        int x = cycle[cycle.size() - 2], y = cycle[cycle.size() - 1];
                        for (auto &z: path[y]) {
                            if (!vis[z] && path[z].find(x) != path[z].end()) {
                                vis[z] = 1;
                                cycle.emplace_back(z);
                                break;
                            }
                        }
                    }
                    
                    int a = cycle[cycle.size() - 2], b = cycle[cycle.size() - 1];
                    if (cycle.size() == n && path[a].find(cycle[0]) != path[a].end() && path[b].find(cycle[0]) != path[b].end() && path[b].find(cycle[1]) != path[b].end()) {
                        for (auto &x: cycle) cout << x << ' ';
                        return 0;
                    }
                }
            }
        }
        cout << -1;
    }

    return 0;
}