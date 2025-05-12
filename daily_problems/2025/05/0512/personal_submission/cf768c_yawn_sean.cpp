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

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> dp(1024, 0), ndp(1024, 0);
    while (n --) {
        int x;
        cin >> x;
        dp[x] ++;
    }

    while (k --) {
        int cur = 0;

        for (int i = 0; i < 1024; i ++) {
            int a = dp[i] - dp[i] / 2, b = dp[i] / 2;

            if (cur) {
                ndp[i ^ x] += b;
                ndp[i] += a;
            }
            else {
                ndp[i ^ x] += a;
                ndp[i] += b;
            }

            cur ^= dp[i] & 1;
        }

        for (int i = 0; i < 1024; i ++) {
            dp[i] = ndp[i];
            ndp[i] = 0;
        }
    }

    int l = -1, r = -1;

    for (int i = 0; i < 1024; i ++) {
        if (dp[i]) {
            l = (l == -1 ? i : l);
            r = i;
        }
    }

    cout << r << ' ' << l;

    return 0;
}