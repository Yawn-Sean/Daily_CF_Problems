
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<std::vector<int>> f(n, std::vector<int>(n, 0));
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            f[u][v] = 1;
        }
        for (int v : g[u]) {
            for (int w : g[u]) {
                f[v][w] = 1;
            }
        }
    }

    std::vector<std::array<int, 2>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (f[i][j]) {
                ans.push_back({i, j});
            }
        }
    }
    std::cout << ans.size() << "\n";
    for (auto [u, v] : ans) {
        std::cout << (u + 1) << " " << (v + 1) << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
