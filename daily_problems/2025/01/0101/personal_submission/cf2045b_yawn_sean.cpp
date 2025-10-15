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

    long long n, d, s;
    cin >> n >> d >> s;

    n /= s;
    d /= s;

    if (n <= d + 1) cout << n * s;
    else {
        n = min(n, 2 * d);
        for (int i = 2; i <= 1000000; i ++) {
            if (n % i == 0 && n - n / i <= d) {
                return cout << n * s, 0;
            }
        }
        cout << (n - 1) * s;
    }

    return 0;
}