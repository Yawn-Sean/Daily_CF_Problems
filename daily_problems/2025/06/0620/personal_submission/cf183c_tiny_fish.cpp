#include <bits/stdc++.h>

using std::cin, std::cout, std::ios;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;

    std::vector e(n, std::vector < std::pair <int, int> > ());
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v; u--, v--;
        e[u].emplace_back(v, 1); e[v].emplace_back(u, -1);
    }

    std::vector <int> f(n, -1e6);
    int ans = 0;

    auto dfs = [&](auto &&self, int u) -> void {
        for(auto &[v, w] : e[u]) {
            if(f[v] > -1e6) {
                ans = std::gcd(ans, std::abs(f[u] - f[v] + w));
            } else {
                f[v] = f[u] + w;
                self(self, v);
            }
        }
    };

    for(int i = 0; i < n; i++) {
        if(f[i] == -1e6) {
            f[i] = 0;
            dfs(dfs, i);
        }
    }

    if(ans)
        cout << ans << '\n';
    else
        cout << n << '\n';

    return 0;
}