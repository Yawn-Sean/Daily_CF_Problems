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

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mod = 1e9 + 7;
    cin >> n;

    vector<int> cnt(30);
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        cnt[31 - __builtin_clz(x & -x)] ++;
    }

    int ans = quickPow(2, n, mod) - quickPow(2, n - cnt[0], mod);
    if (ans < 0) ans += mod;

    int resid = n - cnt[0];

    for (int i = 1; i < 30; i ++) {
        resid -= cnt[i];
        if (cnt[i] >= 2) {
            ans += (quickPow(2, cnt[i] - 1, mod) - 1) * quickPow(2, resid, mod) % mod;
            if (ans >= mod) ans -= mod;
        }
    }
    
    cout << ans;

    return 0;
}