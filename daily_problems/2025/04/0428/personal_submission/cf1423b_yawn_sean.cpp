#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
// #include "atcoder/math"
#include "atcoder/maxflow"
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

    vector<int> us(m), vs(m), ds(m);
    for (int i = 0; i < m; i ++) {
        cin >> us[i] >> vs[i] >> ds[i];
        us[i] --, vs[i] --;
    }

    int inf = 1e9;
    int l = 0, r = inf;

    while (l <= r) {
        int mid = (l + r) / 2;
        atcoder::mf_graph<int> mf(2 * n + 2);

        int src = 2 * n, dst = src + 1;
        for (int i = 0; i < m; i ++) {
            if (ds[i] <= mid) {
                mf.add_edge(us[i], n + vs[i], 1);
            }
        }

        for (int i = 0; i < n; i ++) {
            mf.add_edge(src, i, 1);
            mf.add_edge(n + i, dst, 1);
        }

        if (mf.flow(src, dst) == n) r = mid - 1;
        else l = mid + 1;
    }

    cout << (l <= inf ? l : -1);

    return 0;
}