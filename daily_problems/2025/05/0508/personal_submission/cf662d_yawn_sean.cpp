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

    int t;
    cin >> t;

    while (t --) {
        string s;
        cin >> s;

        long long cur = 1988, v10 = 1, to_add = 1, resid = 0;

        for (int i = s.size() - 1; i >= 4; i --) {
            resid = resid + v10 * (s[i] - '0');
            v10 *= 10;

            cur += to_add;
            while (cur % v10 != resid)
                cur += to_add;

            to_add *= 10;
        }

        cout << cur << '\n';
    }

    return 0;
}