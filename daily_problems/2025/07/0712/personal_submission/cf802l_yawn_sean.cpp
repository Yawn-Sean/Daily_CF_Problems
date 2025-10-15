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

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v, c;
        cin >> u >> v >> c;
        path[u].emplace_back(v, c);
        path[v].emplace_back(u, c);
    }

    vector<int> ks(n, 0), bs(n, 0);
    int mod = 1e9 + 7;

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    auto dfs = [&] (auto &self, int u, int p) -> void {
        if (path[u].size() == 1 && u) return ;

        int sumk = 0, sumb = 0, sumc = 0;
        for (auto &[v, w]: path[u]) {
            add(sumc, w);
            if (v != p) {
                self(self, v, u);
                add(sumk, ks[v]);
                add(sumb, bs[v]);
            }
        }

        int rev = quickPow((path[u].size() - sumk + mod) % mod, mod - 2, mod);
        ks[u] = rev;
        bs[u] = 1ll * (sumb + sumc) % mod * rev % mod;
    };

    dfs(dfs, 0, -1);

    cout << bs[0];

    return 0;
}