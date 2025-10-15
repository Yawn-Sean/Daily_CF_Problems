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

    int n;
    cin >> n;

    vector<vector<int>> dis(n, vector<int>(n, n + 1));
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        dis[i][i] = 0;
        for (int j = 0; j < n; j ++) {
            if (s[j] == '1') {
                dis[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            for (int k = 0; k < n; k ++) {
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }

    int m;
    cin >> m;

    vector<int> route(m);
    for (auto &v: route) cin >> v, v --;

    vector<int> ans = {route[0]};
    int pt = 0, npt;
    while (pt < m - 1) {
        npt = pt;
        while (npt < m - 1 && dis[route[pt]][route[npt + 1]] == dis[route[pt]][route[npt]] + 1) npt ++;
        ans.emplace_back(route[npt]);
        pt = npt;
    }

    cout << ans.size() << '\n';
    for (auto &x: ans)
        cout << x + 1 << ' ';

    return 0;
}