#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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

    int n;
    cin >> n;

    vector<int> us, vs, ts;
    vector<vector<int>> path(n);

    for (int eid = 0; eid < n - 1; eid ++) {
        int u, v, t;
        cin >> u >> v >> t;

        u --, v --;
        us.emplace_back(u);
        vs.emplace_back(v);
        ts.emplace_back(t);

        path[u].emplace_back(eid);
        path[v].emplace_back(eid);
    }


    vector<vector<int>> nth_parent(20, vector<int>(n, -1));
    vector<int> parent_eid(n), depth(n, 0), order;

    auto dfs = [&] (auto &self, int u, int p) -> void {
        order.emplace_back(u);

        for (auto &eid: path[u]) {
            int v = us[eid] + vs[eid] - u;
            if (v != p) {
                nth_parent[0][v] = u;
                parent_eid[v] = eid;
                depth[v] = depth[u] + 1;
                self(self, v, u);
            }
        }
    };

    dfs(dfs, 0, -1);

    for (int i = 1; i < 20; i ++) {
        for (int u = 0; u < n; u ++) {
            if (nth_parent[i - 1][u] != -1) {
                nth_parent[i][u] = nth_parent[i - 1][nth_parent[i - 1][u]];
            }
        }
    }

    auto lca = [&] (int u, int v) -> int {
        if (depth[u] < depth[v]) swap(u, v);

        int d = depth[u] - depth[v];

        for (int i = 0; i < 20; i ++) {
            if (d >> i & 1) {
                u = nth_parent[i][u];
            }
        }

        if (u == v) return u;

        for (int i = 19; i >= 0; i --) {
            if (nth_parent[i][u] != nth_parent[i][v]) {
                u = nth_parent[i][u];
                v = nth_parent[i][v];
            }
        }

        return nth_parent[0][u];
    };

    vector<int> ups(n, 0), downs(n, 0);

    int mod = 1e9 + 7;

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    int k;
    cin >> k;

    vector<int> pw2(k + 1, 0); pw2[0] = 1;
    for (int i = 1; i <= k; i ++) {
        pw2[i] = pw2[i - 1];
        add(pw2[i], pw2[i - 1]);
    }

    int u = 0;
    while (k --) {
        int v;
        cin >> v;
        v --;

        int l = lca(u, v);
        ups[u] ++;
        ups[l] --;
        downs[v] ++;
        downs[l] --;

        u = v;
    }

    reverse(order.begin(), order.end());
    for (auto &i: order) {
        if (i) {
            ups[nth_parent[0][i]] += ups[i];
            downs[nth_parent[0][i]] += downs[i];
        }
    }

    int ans = 0;
    for (int i = 1; i < n; i ++) {
        if (ts[parent_eid[i]]) {
            add(ans, pw2[(i == us[parent_eid[i]] ? downs[i] : ups[i])] - 1);
        }
    }

    cout << ans;

    return 0;
}