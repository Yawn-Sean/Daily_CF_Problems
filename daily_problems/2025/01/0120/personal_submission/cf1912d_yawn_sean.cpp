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

    while (t --) {
        int b, n;
        cin >> b >> n;
        int cur = 1;
        bool flg = true;

        for (int i = 1; i <= n; i ++) {
            cur = 1ll * cur * b % n;
            if (cur == 0) {
                cout << "1 " << i << '\n';
                flg = false;
                break;
            }
            if (cur == 1) {
                cout << "2 " << i << '\n';
                flg = false;
                break;
            }
            if (cur == n - 1) {
                cout << "3 " << i << '\n';
                flg = false;
                break;
            }
        }

        if (flg) cout << "0\n";
    }

    return 0;
}