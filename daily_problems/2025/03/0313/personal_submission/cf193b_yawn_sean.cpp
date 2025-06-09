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

    int n, u, r;
    cin >> n >> u >> r;

    vector<int> a(n), b(n), k(n), p(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    for (auto &x: k) cin >> x;
    for (auto &x: p) cin >> x, x --;

    long long ans = -1e18;

    auto dfs = [&] (auto &self, vector<int> &cur, int steps, bool last_op) -> void {
        if (((u - steps) & 1) == 0) {
            long long res = 0;
            for (int i = 0; i < n; i ++)
                res += cur[i] * k[i];
            ans = max(ans, res);
        }
        if (steps == u) return ;

        steps ++;
        vector<int> ncur(n);
        for (int i = 0; i < n; i ++)
            ncur[i] = cur[p[i]] + r;
        self(self, ncur, steps, false);

        if (!last_op) {
            for (int i = 0; i < n; i ++)
                ncur[i] = cur[i] ^ b[i];
            self(self, ncur, steps, true);
        }
    };

    dfs(dfs, a, 0, false);
    cout << ans;

    return 0;
}