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

    int n, q;
    cin >> n >> q;

    vector<int> parent(n, -1);
    for (int i = 1; i < n; i ++) {
        cin >> parent[i];
        parent[i] --;
    }

    vector<vector<int>> path(n);
    for (int i = 1; i < n; i ++)
        path[parent[i]].push_back(i);

    vector<int> order, pos(n, -1), sz(n, 1);

    auto dfs = [&] (auto &self, int u) -> void {
        pos[u] = order.size();
        order.emplace_back(u);
        for (auto &v: path[u]) {
            self(self, v);
            sz[u] += sz[v];
        }
    };

    dfs(dfs, 0);

    while (q --) {
        int u, k;
        cin >> u >> k;
        u --;
        cout << (k <= sz[u] ? order[pos[u] + k - 1] + 1 : -1) << '\n';
    }

    return 0;
}