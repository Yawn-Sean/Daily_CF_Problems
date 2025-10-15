#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    int ans = 0, cur = 1, mod = 1e9 + 7;

    for (int i = n - 1; i >= 0; i --) {
        ans += ans;
        if (ans >= mod) ans -= mod;

        if (s[i] == '1') {
            ans += 1ll * cur * cur % mod;
            if (ans >= mod) ans -= mod;
        }

        cur += cur;
        if (cur >= mod) cur -= mod;
    }

    cout << ans;

    return 0;
}