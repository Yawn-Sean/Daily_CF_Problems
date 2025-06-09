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

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, w, b;
    cin >> n >> w >> b;

    int mod = 1e9 + 9;

    vector<int> f(10000), g(10000);

    f[0] = 1;
    for (int i = 1; i < 10000; i ++)
        f[i] = 1ll * f[i - 1] * i % mod;
    
    g[9999] = quickPow(f[9999], mod - 2, mod);
    for (int i = 9999; i >= 1; i --)
        g[i - 1] = 1ll * g[i] * i % mod;
    
    auto comb = [&] (int x, int y) -> int {
        if (y < 0 || y > x) return 0;
        return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
    };

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    int ans = 0;
    for (int bad = 1; bad < n - 1; bad ++)
        add(ans, 1ll * comb(b - 1, bad - 1) * comb(w - 1, n - bad - 1) % mod * (n - 1 - bad) % mod);
    
    cout << 1ll * ans * f[w] % mod * f[b] % mod;

    return 0;
}