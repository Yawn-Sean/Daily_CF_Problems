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

    string s;
    cin >> s;

    int n = s.size();
    s += s[0];

    long long dp0, dp1, ans = 0;

    dp0 = 1, dp1 = 0;
    for (int i = 0; i < n; i ++) {
        long long ndp0, ndp1;
        if (s[i] == 'A') {
            ndp0 = dp0 + dp1;
            ndp1 = (s[i + 1] == 'A' ? 0 : dp1);
        }
        else {
            ndp0 = dp1;
            ndp1 = (s[i + 1] == 'A' ? dp0 : dp1);
        }
        dp0 = ndp0, dp1 = ndp1;
    }

    ans += dp0;

    dp0 = 0, dp1 = 1;
    for (int i = 0; i < n; i ++) {
        long long ndp0, ndp1;
        if (s[i] == 'A') {
            ndp0 = dp0 + dp1;
            ndp1 = (s[i + 1] == 'A' ? 0 : dp1);
        }
        else {
            ndp0 = dp1;
            ndp1 = (s[i + 1] == 'A' ? dp0 : dp1);
        }
        dp0 = ndp0, dp1 = ndp1;
    }

    ans += dp1;

    cout << ans;

    return 0;
}