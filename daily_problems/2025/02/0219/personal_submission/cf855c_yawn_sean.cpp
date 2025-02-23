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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int mod = 1e9 + 7;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> path(n);

    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    int k, x;
    cin >> k >> x;

    vector<vector<int>> dp0(x + 1, vector<int>(n, 0)), dp1(x + 1, vector<int>(n, 0)), dp2(x + 1, vector<int>(n, 0));

    for (int i = 0; i < n; i ++) {
        dp0[0][i] = k - 1;
        dp1[1][i] = 1;
        dp2[0][i] = m - k;
    }

    auto dp = [&] (auto &self, int u, int p) -> void {
        for (auto &v: path[u]) {
            if (v != p) {
                self(self, v, u);
                
                for (int nx = x; nx >= 0; nx --) {
                    long long res = 0;
                    for (int nx0 = 0; nx0 <= nx; nx0 ++) {
                        res += (0ll + dp0[nx0][v] + dp1[nx0][v] + dp2[nx0][v]) * dp0[nx - nx0][u] % mod;
                    }
                    dp0[nx][u] = res % mod;
                }

                for (int nx = x; nx >= 0; nx --) {
                    long long res = 0;
                    for (int nx0 = 0; nx0 <= nx; nx0 ++) {
                        res += 1ll * dp0[nx0][v] * dp1[nx - nx0][u] % mod;
                    }
                    dp1[nx][u] = res % mod;
                }

                for (int nx = x; nx >= 0; nx --) {
                    long long res = 0;
                    for (int nx0 = 0; nx0 <= nx; nx0 ++) {
                        res += 1ll * (dp0[nx0][v] + dp2[nx0][v]) * dp2[nx - nx0][u] % mod;
                    }
                    dp2[nx][u] = res % mod;
                }
            }
        }
    };
    
    dp(dp, 0, -1);

    long long ans = 0;

    for (int i = 0; i <= x; i ++) {
        ans += dp0[i][0];
        ans += dp1[i][0];
        ans += dp2[i][0];
    }
    
    cout << ans % mod;

    return 0;
}