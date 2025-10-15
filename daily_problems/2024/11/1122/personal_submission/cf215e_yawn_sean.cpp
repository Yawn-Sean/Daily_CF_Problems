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

long long f(long long x) {
    int k = (x ? 64 - __builtin_clzll(x) : 0);
    vector<long long> ans(k + 1, 0);

    for (int l = 1; l < k; l ++) {
        for (int divisor = 1; divisor < l; divisor ++) {
            if (l % divisor == 0) {
                ans[l / divisor] += 1ll << (divisor - 1);
            }
        }
    }

    for (int divisor = 1; divisor < k; divisor ++) {
        if (k % divisor == 0) {
            long long msk = 0;
            for (int j = 0; j < k; j += divisor) {
                msk |= 1ll << j;
            }
            ans[k / divisor] += max(0ll, x / msk - (1ll << (divisor - 1)) + 1);
        }
    }

    long long res = 0;
    for (int i = k; i > 1; i --) {
        for (int j = i * 2; j <= k; j += i)
            ans[i] -= ans[j];
        res += ans[i];
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1);

    return 0;
}