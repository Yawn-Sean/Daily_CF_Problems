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

    int n, k, mod = 1e9 + 7;
    long long m;

    cin >> n >> m >> k;

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    vector<vector<int>> combs(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i ++) {
        combs[i][0] = 1;
        for (int j = 1; j <= i; j ++) {
            combs[i][j] = combs[i - 1][j];
            add(combs[i][j], combs[i - 1][j - 1]);
        }
    }

    long long a = m / n, b = m % n;

    vector<int> dp(k + 1, 0), ndp(k + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= n; j ++) {
            int v = quickPow(combs[n][j], (i < b ? a + 1 : a), mod);
            for (int cur = 0; cur + j <= k; cur ++) {
                if (dp[cur]) add(ndp[cur + j], 1ll * dp[cur] * v % mod);
            }
        }
        for (int j = 0; j <= k; j ++) {
            dp[j] = ndp[j];
            ndp[j] = 0;
        }
    }

    cout << dp[k];

    return 0;
}