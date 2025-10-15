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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    for (int ca = 0; ca <= n / a; ca ++) {
        if ((n - a * ca) % b == 0) {
            int cb = (n - a * ca) / b;

            int cur = 1;
            while (ca --) {
                for (int i = 1; i < a; i ++)
                    cout << cur + i << ' ';
                cout << cur << ' ';
                cur += a;
            }

            while (cb --) {
                for (int i = 1; i < b; i ++)
                    cout << cur + i << ' ';
                cout << cur << ' ';
                cur += b;
            }

            return 0;
        }
    }

    cout << -1;

    return 0;
}