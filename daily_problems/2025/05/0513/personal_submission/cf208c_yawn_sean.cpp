#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> path(n);

    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> dis1(n, -1), que = {0};
    dis1[0] = 0;

    for (int pt = 0; pt < que.size(); pt ++) {
        int u = que[pt];
        for (auto &v: path[u]) {
            if (dis1[v] == -1) {
                dis1[v] = dis1[u] + 1;
                que.emplace_back(v);
            }
        }
    }

    vector<long long> dp1(n, 0);
    dp1[0] = 1;

    for (auto &u: que) {
        for (auto &v: path[u]) {
            if (dis1[v] + 1 == dis1[u]) {
                dp1[u] += dp1[v];
            }
        }
    }

    vector<int> disn(n, -1);
    disn[n - 1] = 0;

    que.clear();
    que.emplace_back(n - 1);

    for (int pt = 0; pt < que.size(); pt ++) {
        int u = que[pt];
        for (auto &v: path[u]) {
            if (disn[v] == -1) {
                disn[v] = disn[u] + 1;
                que.emplace_back(v);
            }
        }
    }

    vector<long long> dpn(n, 0);
    dpn[n - 1] = 1;

    for (auto &u: que) {
        for (auto &v: path[u]) {
            if (disn[v] + 1 == disn[u]) {
                dpn[u] += dpn[v];
            }
        }
    }

    long long ans = dp1[n - 1];

    for (int i = 1; i < n - 1; i ++) {
        long long res = 0;
        for (auto &j1: path[i]) {
            for (auto &j2: path[i]) {
                if (dis1[j1] + disn[j2] + 2 == dis1[n - 1]) {
                    res += dp1[j1] * dpn[j2];
                }
            }
        }
        ans = max(ans, res * 2);
    }

    cout << fixed << setprecision(15) << (long double)1.0 * ans / dp1[n - 1];

    return 0;
}