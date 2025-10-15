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

    vector<int> verti(n), hori;
    for (auto &v: verti) cin >> v;

    for (int i = 0; i < m; i ++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 == 1) hori.emplace_back(x2);
    }

    sort(verti.begin(), verti.end());
    sort(hori.begin(), hori.end());

    verti.emplace_back((int)1e9);

    m = hori.size();
    int ans = n + m, pt = m - 1;

    for (int i = n; i >= 0; i --) {
        while (pt >= 0 && hori[pt] >= verti[i])
           pt --;
        ans = min(ans, i + m - pt - 1);
    }

    cout << ans;

    return 0;
}