#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mod = 1e9 + 7;
    cin >> n;

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> dp0(n, 0), dp1(n, 0), dp2(n, 0);

    auto dfs = [&] (auto &self, int u, int p) -> void {
        int v1 = 0, v2 = 0, v3 = 1, s1 = 0, s2 = 1;

        for (auto &v: path[u]) {
            if (v != p) {
                self(self, v, u);

                v1 = (1ll * v1 * dp2[v] + 1ll * v2 * dp1[v]) % mod;
                v2 = (1ll * v2 * dp2[v] + 1ll * v3 * dp1[v]) % mod;
                v3 = 1ll * v3 * dp2[v] % mod;

                s1 = (1ll * s1 * dp0[v] + 1ll * s2 * dp1[v]) % mod;
                s2 = 1ll * s2 * dp0[v] % mod;
            }
        }

        dp0[u] = v1, dp1[u] = (v2 + s2) % mod, dp2[u] = ((dp0[u] + s1) % mod + s2) % mod;
    };

    dfs(dfs, 0, -1);

    cout << dp2[0];

    return 0;
}