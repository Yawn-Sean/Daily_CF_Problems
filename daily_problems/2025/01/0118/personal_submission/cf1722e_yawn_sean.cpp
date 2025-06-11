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

    int t;
    cin >> t;

    vector<vector<long long>> pref(1001, vector<long long>(1001));

    while (t --) {
        int n, q;
        cin >> n >> q;

        while (n --) {
            int x, y;
            cin >> x >> y;
            pref[x][y] += x * y;
        }

        for (int i = 0; i < 1000; i ++) {
            for (int j = 0; j <= 1000; j ++) {
                pref[i + 1][j] += pref[i][j];
            }
        }

        for (int i = 0; i <= 1000; i ++) {
            for (int j = 0; j < 1000; j ++) {
                pref[i][j + 1] += pref[i][j];
            }
        }

        while (q --) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            cout << pref[hb - 1][wb - 1] - pref[hs][wb - 1] - pref[hb - 1][ws] + pref[hs][ws] << '\n';
        }

        for (int i = 0; i <= 1000; i ++) {
            for (int j = 0; j <= 1000; j ++) {
                pref[i][j] = 0;
            }
        }
    }

    return 0;
}