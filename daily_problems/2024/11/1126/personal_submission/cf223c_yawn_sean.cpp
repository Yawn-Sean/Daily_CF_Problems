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

// Let's flow!
long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, mod = 1e9 + 7;
    cin >> n >> k;

    vector<int> nums(n), f(n + 1, 1), g(n + 1, 1);
    for (auto &v: nums)
        cin >> v;

    for (int i = 1; i <= n; i ++)
        f[i] = 1ll * f[i - 1] * i % mod;
    
    g[n] = quickPow(f[n], mod - 2, mod);

    for (int i = n; i > 0; i --)
        g[i - 1] = 1ll * g[i] * i % mod;
    
    vector<int> combs(n, 1);
    for (int i = 1; i < n; i ++) {
        combs[i] = 1ll * combs[i - 1] * (k + i - 1) % mod * f[i - 1] % mod * g[i] % mod;
    }

    for (int i = 0; i < n; i ++) {
        int v = 0;
        for (int j = 0; j <= i; j ++) {
            v += 1ll * nums[j] * combs[i - j] % mod;
            if (v >= mod) v -= mod;
        }
        cout << v << ' ';
    }

    return 0;
}