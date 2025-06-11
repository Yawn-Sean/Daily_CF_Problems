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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

    vector<vector<pair<int, int>>> path(n);

    for (int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        path[u].emplace_back(v, w);
        path[v].emplace_back(u, w);
    }

    int inf = 1e9;

    vector<int> dis1(n, inf), disn(n, inf), parent(n, -1);
    vector<bool> vis(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis1[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dis1[u] == d) {
            for (auto &[v, w]: path[u]) {
                if (dis1[v] > d + w) {
                    dis1[v] = w + d;
                    parent[v] = u;
                    pq.push({dis1[v], v});
                }
            }
        }
    }

    int cur = n - 1;
    vis[cur] = 1;

    while (parent[cur] >= 0) {
        cur = parent[cur];
        vis[cur] = 1;
    }

    disn[n - 1] = 0;
    pq.push({0, n - 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (disn[u] == d) {
            for (auto &[v, w]: path[u]) {
                if (disn[v] > d + w) {
                    disn[v] = w + d;
                    parent[v] = u;
                    pq.push({disn[v], v});
                }
            }
        }
    }

    int ans = inf;

    for (int u = 0; u < n; u ++) {
        for (auto &[v, w]: path[u]) {
            if (vis[u] && vis[v] && (parent[u] == v || parent[v] == u)) continue;
            ans = min(ans, dis1[u] + disn[v] + w);
        }
    }

    cout << (ans < inf ? ans + dis1[n - 1] : -1);

    return 0;
}