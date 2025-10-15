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
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> pairs(m);
    for (auto &[u, v]: pairs) cin >> u >> v;

    if (n <= 6) cout << m;
    else {
        int ans = 0;
        for (int i = 1; i <= 7; i ++) {
            for (int j = 1; j < i; j ++) {
                set<pair<int, int>> st;
                for (auto [u, v]: pairs) {
                    if (u == i) u = j;
                    if (v == i) v = j;
                    if (u > v) swap(u, v);
                    st.insert({u, v});
                }
                ans = max(ans, (int)st.size());
            }
        }
        cout << ans;
    }

    return 0;
}