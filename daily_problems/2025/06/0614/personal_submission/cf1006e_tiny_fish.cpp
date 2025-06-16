#include <bits/stdc++.h>

using std::cin, std::cout, std::ios;

int main() {
    int n, q; cin >> n >> q;
    std::vector e(n, std::vector <int> ());

    for(int i = 1, p; i < n; i++) {
        cin >> p; e[p-1].emplace_back(i);
    }

    std::vector <int> f(n), g(n), sz(n); int idx = 0;
    auto dfs = [&](auto &&self, int u) -> void {
        f[u] = idx, g[idx] = u, idx ++; sz[u] = 1;
        for(auto &v : e[u])
            self(self, v), sz[u] += sz[v]; 
    };
    dfs(dfs, 0);

    while(q--) {
        int u, k; cin >> u >> k; u--, k--;
        if(sz[u] <= k)
            cout << -1 << '\n';
        else
            cout << g[f[u] + k] + 1 << '\n';
    }

    return 0;
}