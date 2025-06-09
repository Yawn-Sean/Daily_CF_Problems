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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vis(n);
    while (m --) {
        int u, v;
        cin >> u >> v;
        if (v - u == k + 1) vis[u] = 1;
        else if (v - u != 1) return cout << 0, 0;
    }

    for (int i = 1; i < n; i ++)
        vis[i] += vis[i - 1];
    
    int ans = 0, mod = 1e9 + 7;
    vector<int> pw2(n + 1, 1);

    for (int i = 1; i <= n; i ++) {
        pw2[i] = pw2[i - 1] + pw2[i - 1];
        if (pw2[i] >= mod) pw2[i] -= mod;
    }

    if (!vis.back()) ans ++;
    for (int i = 0; i < n - k - 1; i ++) {
        if (!vis[i] && vis[i + k + 1] == vis.back()) {
            int r = min(i + k, n - k - 2);
            ans += pw2[r - i - (vis[r + 1] - vis[i + 1])];
            if (ans >= mod) ans -= mod;
        }
    }

    cout << ans;

    return 0;
}