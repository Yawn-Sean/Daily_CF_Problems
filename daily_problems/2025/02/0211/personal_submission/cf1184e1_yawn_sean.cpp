#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
#include "atcoder/dsu"
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

    vector<int> us(m), vs(m), ws(m);

    for (int i = 0; i < m; i ++) {
        cin >> us[i] >> vs[i] >> ws[i];
        us[i] --, vs[i] --;
    }

    vector<int> order(m - 1);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(), [&] (int i, int j) {return ws[i] < ws[j];});

    atcoder::dsu uf(n), uf1(n);
    uf.merge(us[0], vs[0]);

    for (auto &i: order) {
        if (uf.leader(us[i]) != uf.leader(vs[i])) {
            uf.merge(us[i], vs[i]);
            uf1.merge(us[i], vs[i]);
        }
    }

    for (auto &i: order) {
        if (uf1.leader(us[i]) != uf1.leader(vs[i])) {
            return cout << ws[i], 0;
        }
    }
    cout << "1000000000";

    return 0;
}