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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 2>>> pts(n + 1);

    for (int i = 1; i <= n; i ++)
        pts[i].push_back({i, i});
    
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        pts[u].push_back({n + i + 1, u});
        pts[v].push_back({n + i + 1, v});
    }

    for (int i = 1; i <= n; i ++) {
        cout << pts[i].size() << '\n';
        for (auto &x: pts[i])
            cout << x[0] << ' ' << x[1] << '\n';
    }

    return 0;
}