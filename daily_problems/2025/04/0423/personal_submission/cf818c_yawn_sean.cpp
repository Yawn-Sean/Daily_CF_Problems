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

    int d, n, m;
    cin >> d >> n >> m;

    vector<int> cols_l(n + 2, 0), cols_r(n + 2, 0), rows_u(m + 2, 0), rows_d(m + 2, 0);
    vector<int> x1s(d), y1s(d), x2s(d), y2s(d);

    for (int i = 0; i < d; i ++) {
        cin >> x1s[i] >> y1s[i] >> x2s[i] >> y2s[i];
        if (x1s[i] > x2s[i]) swap(x1s[i], x2s[i]);
        if (y1s[i] > y2s[i]) swap(y1s[i], y2s[i]);

        cols_l[x1s[i]] ++, cols_r[x2s[i]] ++;
        rows_u[y1s[i]] ++, rows_d[y2s[i]] ++;
    }

    for (int i = 1; i <= n; i ++) cols_l[i] += cols_l[i - 1];
    for (int i = n; i >= 0; i --) cols_r[i] += cols_r[i + 1];
    for (int i = 1; i <= m; i ++) rows_u[i] += rows_u[i - 1];
    for (int i = m; i >= 0; i --) rows_d[i] += rows_d[i + 1];

    int cl, cr, cu, cd;
    cin >> cl >> cr >> cu >> cd;

    for (int i = 0; i < d; i ++) {
        int vcl = cols_l[x2s[i] - 1];
        int vcr = cols_r[x1s[i] + 1];
        int vcu = rows_u[y2s[i] - 1];
        int vcd = rows_d[y1s[i] + 1];

        if (x1s[i] < x2s[i])
            vcl --, vcr --;
        else 
            vcu --, vcd --;
        
        if (cl == vcl && cr == vcr && cu == vcu && cd == vcd) 
            return cout << i + 1, 0;
    }

    cout << -1;

    return 0;
}