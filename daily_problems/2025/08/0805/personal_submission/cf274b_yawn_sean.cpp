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

    int n;
    cin >> n;

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        path[u].emplace_back(v);
        path[v].emplace_back(u);
    }

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<long long> f(n, 0), g(n, 0);

    auto dfs = [&] (auto &self, int u, int p) -> void {
        for (auto &v: path[u])
            if (v != p) self(self, v, u);
        
        for (auto &v: path[u]) {
            if (v != p) {
                f[u] = max(f[u], f[v]);
                g[u] = max(g[u], g[v]);
            }
        }

        long long k = nums[u] + f[u] - g[u];
        if (k > 0) g[u] += k;
        else f[u] -= k;
    };

    dfs(dfs, 0, -1);

    cout << f[0] + g[0];

    return 0;
}