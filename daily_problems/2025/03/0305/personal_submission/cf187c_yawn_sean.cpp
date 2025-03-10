#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
#include "atcoder/dsu"
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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ispos(n + 1, 0);
    for (int i = 0; i < k; i ++) {
        int x;
        cin >> x;
        ispos[x] = 1;
    }

    vector<pair<int, int>> edges(m);
    vector<vector<int>> path(n + 1);

    for (auto &[u, v]: edges) {
        cin >> u >> v;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    int s, t;
    cin >> s >> t;
    ispos[t] = 1;

    vector<int> que(n + 5, 0), froms(n + 1, -1), dis(n + 1, n);
    int pl = 0, pr = 0;

    for (int i = 0; i <= n; i ++) {
        if (ispos[i]) {
            dis[i] = 0;
            froms[i] = i;
            que[pr ++] = i;
        }
    }

    while (pl < pr) {
        int u = que[pl ++];
        for (auto &v: path[u]) {
            if (dis[v] == n) {
                dis[v] = dis[u] + 1;
                froms[v] = froms[u];
                que[pr ++] = v;
            }
        }
    }

    vector<vector<int>> tmp(n);
    for (int i = 0; i < m; i ++) {
        auto &[u, v] = edges[i];
        int w = (froms[u] == froms[v] ? max(dis[u], dis[v]) : dis[u] + dis[v] + 1);
        if (w < n) tmp[w].emplace_back(i);
    }

    atcoder::dsu uf(n + 1);
    for (int i = 0; i < n; i ++) {
        for (auto &j: tmp[i]) {
            auto &[u, v] = edges[j];
            uf.merge(u, v);
            if (uf.leader(s) == uf.leader(t))
                return cout << i, 0;
        }
    }
    cout << -1;

    return 0;
}