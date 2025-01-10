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

    int n, m, inf = 1e9;
    cin >> n >> m;

    vector<array<int, 4>> ops(m);

    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < 4; j ++) {
            cin >> ops[i][j];
        }
    }

    vector<int> cur_diff(n, 0), ans(n, inf);
    for (int i = 0; i < m; i ++) {
        if (ops[i][0] == 1) {
            for (int j = ops[i][1] - 1; j < ops[i][2]; j ++) {
                cur_diff[j] += ops[i][3];
            }
        }
        else {
            for (int j = ops[i][1] - 1; j < ops[i][2]; j ++) {
                ans[j] = min(ans[j], ops[i][3] - cur_diff[j]);
            }
        }
    }

    vector<int> tmp = ans;
    for (int i = 0; i < m; i ++) {
        if (ops[i][0] == 1) {
            for (int j = ops[i][1] - 1; j < ops[i][2]; j ++) {
                tmp[j] += ops[i][3];
            }
        }
        else {
            int v = -inf;
            for (int j = ops[i][1] - 1; j < ops[i][2]; j ++) {
                v = max(v, tmp[j]);
            }
            if (v != ops[i][3]) return cout << "NO", 0;
        }
    }

    cout << "YES\n";
    for (auto &x: ans) cout << x << ' ';

    return 0;
}