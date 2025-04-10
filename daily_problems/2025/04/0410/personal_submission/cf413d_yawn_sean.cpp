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

    int n, k;
    cin >> n >> k;

    int total = 1 << (k - 1), mod = 1e9 + 7, ans = 0;

    vector<int> dp(total, 0), ndp(total, 0);
    dp[0] = 1;

    auto add = [&] (int &x, int y) {
        x += y;
        if (x >= mod) x -= mod;
    };

    while (n --) {
        int x;
        cin >> x;
        x /= 2;

        if (x == 0) add(ans, ans);

        if (x != 2) {
            for (int i = 0; i < total - 1; i ++)
                add(ndp[i + 1], dp[i]);
            add(ans, dp[total - 1]);
        }

        if (x != 1) {
            for (int i = 1; i < total; i += 2)
                add(ndp[2], dp[i]);
            for (int i = 0; i < total - 2; i += 2)
                add(ndp[i + 2], dp[i]);
            add(ans, dp[total - 2]);
        }

        for (int i = 0; i < total; i ++)
            dp[i] = ndp[i], ndp[i] = 0;
    }

    cout << ans;

    return 0;
}