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
        int x;
        cin >> x;
        if (x == 0) cout << "1 1\n";
        else {
            bool flg = false;
            for (int i = 1; i * i < x; i ++) {
                if (x % i == 0) {
                    int a = x / i, b = i;
                    int n = (a + b) / 2, m = (a + b) / (a - b);
                    if (1ll * n * n - 1ll * (n / m) * (n / m) == x) {
                        flg = true;
                        cout << n << ' ' << m << '\n';
                        break;
                    }
                }
            }
            if (!flg) cout << "-1\n";
        }
    }

    return 0;
}