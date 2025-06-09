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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

    vector<int> cur(400, 0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> ncur(400, 0);

        bool flg = false;

        for (int i = 0; i < 400; i ++) {
            if (n >= cur[i]) {
                n -= cur[i];
                ncur[i] = cur[i];
            }
            else {
                flg = true;
                for (int j = i - 1; j >= 0; j --) {
                    if (n && ncur[j] != 9) {
                        ncur[j] ++;
                        n --;
                        break;
                    }
                    else {
                        n += ncur[j];
                        ncur[j] = 0;
                    }
                }
                break;
            }
        }

        if (!flg) {
            if (n) {
                ncur.back() ++;
                n --;
            }
            else {
                for (int j = 399; j >= 0; j --) {
                    if (n && ncur[j] != 9) {
                        ncur[j] ++;
                        n --;
                        break;
                    }
                    else {
                        n += ncur[j];
                        ncur[j] = 0;
                    }
                }
            }
        }

        for (int j = 399; j >= 0; j --) {
            int v = min(n, 9 - ncur[j]);
            ncur[j] += v;
            n -= v;
        }

        flg = false;
        cur.swap(ncur);

        for (int j = 0; j < 400; j ++) {
            if (cur[j]) flg = true;
            if (flg) cout << cur[j];
        }
        cout << '\n';
    }

    return 0;
}