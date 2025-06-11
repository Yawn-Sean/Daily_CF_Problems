#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> flg(n, 0);
    for (int i = 0; i < k * 2; i ++) {
        int x;
        cin >> x;
        flg[x - 1] = 1;
    }

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    long long ans = 0;

    auto dfs = [&] (auto &self, int u, int p) -> int {
        int cnt = flg[u];
        for (auto &v: path[u])
            if (v != p) cnt += self(self, v, u);
        ans += min(cnt, 2 * k - cnt);
        return cnt;
    };

    dfs(dfs, 0, -1);
    cout << ans;

    return 0;
}