#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
#include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    int su, sv;

    vector<int> us, vs, ws;
    for (int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        us.emplace_back(u);
        vs.emplace_back(v);
        ws.emplace_back(w);
        su = u, sv = v;
    }

    int components = n;
    atcoder::dsu uf(n);

    for (int i = 0; i < m; i ++)
        components -= uf.merge(us[i], vs[i]);

    vector<int> total(n, 0);
    int inf = 1e9;

    for (int i = 0; i < m; i ++) {
        int u = uf.leader(us[i]);
        total[u] = min(total[u] + ws[i], inf);
    }

    if (components < q || components - p > q || (p && q == n))
        cout << "NO";
    else {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i ++) {
            if (uf.leader(i) == i) {
                pq.push({-total[i], i});
            }
        }

        cout << "YES\n";

        for (int i = 0; i < components - q; i ++) {
            auto [v1, i1] = pq.top(); pq.pop();
            auto [v2, i2] = pq.top(); pq.pop();
            cout << i1 + 1 << ' ' << i2 + 1 << '\n';
            su = i1, sv = i2;
            uf.merge(i1, i2);
            pq.push({max(-inf, 2 * (v1 + v2) - 1), uf.leader(i1)});
        }

        for (int i = 0; i < p - (components - q); i ++)
            cout << su + 1 << ' ' << sv + 1 << '\n';
    }

    return 0;
}