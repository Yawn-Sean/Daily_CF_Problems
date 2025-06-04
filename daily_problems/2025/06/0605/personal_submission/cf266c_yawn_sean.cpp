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

    int n;
    cin >> n;

    vector<pair<int, int>> pts(n - 1);
    for (auto &[x, y]: pts) {
        cin >> x >> y;
        x --, y --;
    }

    vector<array<int, 3>> ops;

    for (int i = n; i > 1; i --) {
        vector<int> cnt_r(i, 0), cnt_c(i, 0);

        for (auto &[x, y]: pts) {
            if (x < i && y < i) {
                cnt_r[x] ++;
                cnt_c[y] ++;
            }
        }

        for (int j = 0; j < i - 1; j ++) {
            if (!cnt_c[j]) {
                ops.push_back({2, j + 1, i});
                for (auto &[x, y]: pts)
                    if (y == i - 1) y = j;
                break;
            }
        }

        for (int j = 0; j < i - 1; j ++) {
            if (cnt_r[j]) {
                ops.push_back({1, j + 1, i});
                for (auto &[x, y]: pts) {
                    if (x == j) x = i - 1;
                    else if (x == i - 1) x = j;
                }
                break;
            }
        }
    }

    cout << ops.size() << '\n';
    for (auto &op: ops)
        cout << op[0] << ' ' << op[1] << ' ' << op[2] << '\n';

    return 0;
}