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

    int t;
    cin >> t;

    while (t --) {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> path(n);

        while (m --) {
            int u, v, w;
            cin >> u >> v >> w;
            u --, v --;

            path[u].emplace_back(v, w);
            path[v].emplace_back(u, w);
        }

        vector<int> bikes(n);
        for (auto &b: bikes) cin >> b;

        long long inf = 1e12;
        vector<vector<long long>> dis(n, vector<long long>(n, inf));

        dis[0][0] = 0;

        priority_queue<tuple<long long, int, int>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [d, u, b] = pq.top();
            pq.pop();
            d = -d;

            if (dis[u][b] != d) continue;

            for (auto &[v, w]: path[u]) {
                long long nd = d + w * bikes[b];
                int nb = (bikes[v] < bikes[b] ? v : b);

                if (dis[v][nb] > nd) {
                    dis[v][nb] = nd;
                    pq.push({-nd, v, nb});
                }
            }
        }

        long long ans = inf;
        for (int b = 0; b < n; b ++) ans = min(ans, dis[n - 1][b]);
        cout << ans << '\n';
    }

    return 0;
}