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

    long long w, m, k;
    cin >> w >> m >> k;
    w /= k;

    long long v = 10, digit = 1, ans = 0;

    while (true) {
        long long l = max(0ll, v - m);
        if (l * digit <= w) {
            w -= l * digit;
            ans += l;
            m += l;
        }
        else {
            ans += w / digit;
            break;
        }

        v *= 10, digit ++;
    }

    cout << ans;

    return 0;
}