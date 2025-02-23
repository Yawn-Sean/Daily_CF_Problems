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

    int n, m;
    cin >> n >> m;

    vector<int> perm(n);
    for (auto &v: perm)
        cin >> v;
    
    vector<vector<int>> path(n + 1);
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        path[u].emplace_back(v);
    }

    vector<int> vis(n + 1, 0);
    vis[perm.back()] = 1;

    int cnt = 1;

    for (int i = n - 2; i >= 0; i --) {
        int v = 0;
        for (auto &j: path[perm[i]])
            v += vis[j];
        if (v < cnt) {
            vis[perm[i]] = 1;
            cnt ++;
        }
    }

    cout << n - cnt;

    return 0;
}