#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, m;
        cin >> n >> m;

        atcoder::dsu uf(n);
        vector<vector<int>> path(n);
        vector<pair<int, int>> edges;

        while (m --) {
            int u, v;
            cin >> u >> v;
            u --, v --;
            
            if (uf.merge(u, v)) {
                path[u].emplace_back(v);
                path[v].emplace_back(u);
            }
            else edges.emplace_back(u, v);
        }

        vector<int> parent(n, -1), depth(n, 0);

        auto dfs = [&] (auto &self, int u, int p) -> void {
            for (auto &v: path[u]) {
                if (v != p) {
                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    self(self, v, u);
                }
            }
        };

        dfs(dfs, 0, -1);

        vector<vector<int>> nth_parent(20, vector<int>(n, -1));
        nth_parent[0] = parent;

        for (int i = 0; i < 19; i ++) {
            for (int j = 0; j < n; j ++) {
                if (nth_parent[i][j] >= 0) {
                    nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]];
                }
            }
        }

        vector<int> sz(n, 1), diff(n, 0);

        for (auto &[u, v]: edges) {
            diff[u] ++, diff[v] ++;
            if (depth[u] < depth[v]) swap(u, v);
            int d = depth[u] - depth[v];

            for (int i = 0; i < 20; i ++) {
                if (d >> i & 1) {
                    u = nth_parent[i][u];
                }
            }

            if (u == v) diff[u] -= 2;
            else {
                for (int i = 19; i >= 0; i --) {
                    if (nth_parent[i][u] != nth_parent[i][v]) {
                        u = nth_parent[i][u];
                        v = nth_parent[i][v];
                    }
                }
                diff[parent[u]] -= 2;
            }
        }

        long long to_delete = 0;

        auto dfs1 = [&] (auto &self, int u, int p) -> void {
            for (auto &v: path[u]) {
                if (v != p) {
                    self(self, v, u);
                    sz[u] += sz[v];
                    diff[u] += diff[v];
                }
            }

            if (diff[u] == 0) to_delete = max(to_delete, 1ll * sz[u] * (n - sz[u]));
        };

        dfs1(dfs1, 0, -1);

        cout << 1ll * n * (n - 1) / 2 - to_delete << '\n';
    }

    return 0;
}