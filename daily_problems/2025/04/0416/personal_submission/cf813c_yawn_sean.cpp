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

    int n, x;
    cin >> n >> x, x --;

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    auto dis = [&] (int u) -> vector<int> {
        vector<int> ans(n, -1);
        ans[u] = 0;
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (auto &v: path[u]) {
                if (ans[v] == -1) {
                    ans[v] = ans[u] + 1;
                    q.push(v);
                }
            }
        }
        return ans;
    };

    auto dis0 = dis(0);
    auto disx = dis(x);

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        if (disx[i] < dis0[i]) {
            ans = max(ans, dis0[i]);
        }
    }

    cout << ans * 2;

    return 0;
}