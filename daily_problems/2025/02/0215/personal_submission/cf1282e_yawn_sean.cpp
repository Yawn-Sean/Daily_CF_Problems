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
        int n;
        cin >> n;

        map<pair<int, int>, int> edge_cnt;
        map<pair<int, int>, vector<int>> edge_from;
        vector<vector<int>> triangles(n - 2, vector<int>(3));

        for (int t_id = 0; t_id < n - 2; t_id ++) {
            for (int i = 0; i < 3; i ++)
                cin >> triangles[t_id][i];
            sort(triangles[t_id].begin(), triangles[t_id].end());
            
            for (int i = 0; i < 3; i ++) {
                for (int j = 0; j < i; j ++) {
                    edge_cnt[{triangles[t_id][j], triangles[t_id][i]}] ++;
                    edge_from[{triangles[t_id][j], triangles[t_id][i]}].emplace_back(t_id);
                }
            }
        }

        vector<vector<int>> path(n + 1);
        for (auto &[e, v]: edge_cnt) {
            if (v == 1) {
                auto &[x, y] = e;
                path[x].emplace_back(y);
                path[y].emplace_back(x);
            }
        }

        vector<int> vis(n + 1, 0), nodes = {1};
        vis[1] = 1;

        for (int _ = 0; _ < n - 1; _ ++) {
            for (auto &v: path[nodes.back()]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    nodes.emplace_back(v);
                    break;
                }
            }
        }

        for (auto &x: nodes) cout << x << ' ';
        cout << '\n';

        vector<int> ans, stk, cnt(n - 2, 3);
        for (int i = 0; i < n; i ++) {
            int u = nodes[i], v = nodes[(i - 1 + n) % n];
            if (u > v) swap(u, v);

            for (auto &t_id: edge_from[{u, v}]) {
                cnt[t_id] --;
                if (cnt[t_id] == 1) stk.emplace_back(t_id);
            }
        }

        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();

            ans.emplace_back(u);

            for (int i = 0; i < 3; i ++) {
                for (int j = 0; j < i; j ++) {
                    for (auto &v: edge_from[{triangles[u][j], triangles[u][i]}]) {
                        if (cnt[v] > 0) {
                            cnt[v] --;
                            if (cnt[v] == 1) stk.emplace_back(v);
                        }
                    }
                }
            }
        }

        for (auto &v: ans) cout << v + 1 << ' ';
        cout << '\n';
    }

    return 0;
}