#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    int n, m;
    cin >> n >> m;

    vector<int> vals(m), bs(m);
    for (int i = 0; i < m; i ++)
        cin >> vals[i] >> bs[i];
    
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return vals[i] * 2 + (1 - bs[i]) < vals[j] * 2 + (1 - bs[j]);});

    vector<int> us(m), vs(m);
    int cur = 2, u = 2, v = 1;

    for (auto &eid: order) {
        if (bs[eid]) {
            us[eid] = 1;
            vs[eid] = cur ++;
        }
        else {
            if (++v == u)
                u ++, v = 2;
            if (u >= cur) 
                return cout << -1, 0;
            us[eid] = u;
            vs[eid] = v;
        }
    }

    for (int i = 0; i < m; i ++)
        cout << us[i] << ' ' << vs[i] << '\n';

    return 0;
}