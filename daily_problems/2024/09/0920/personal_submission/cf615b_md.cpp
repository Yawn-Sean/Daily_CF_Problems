// 0920
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    std::vector<int> deg(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;

        if (u > v) {
            std::swap(u, v);
        }
        graph[u].push_back(v);
        deg[v]++;
        deg[u]++;
    }

    std::vector<int> len(n, 1);
    i64 ans = 0ll;
    for (int i = 0; i < n; ++i) {
        for (auto u : graph[i]) {
            len[u] = std::max(len[u], len[i] + 1);
        }
        ans = std::max(ans, 1ll * len[i] * deg[i]);
    }

    std::cout << ans << '\n';
    return 0;
}