#include <bits/stdc++.h>

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];

    std::vector<int> col(n + 1, -1);
    std::vector<int> vis(1 << 20);

    std::vector adj(n + 1, std::vector<int>());

    for (int i = 1;i <= m;i++) {
        int u, v;   std::cin >> u >> v;
        if (a[u] == a[v]) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else vis[a[u] ^ a[v]] = 1;
    }

    auto dfs = [&](auto&& self, int u) -> void {
        for (auto v : adj[u]) {
            if (col[v] == -1) col[v] = col[u] ^ 1, self(self, v);
            else if (col[v] == col[u]) std::cout << -1, exit(0);
        }
        };

    for (int i = 1;i <= n;i++)
        if (col[i] == -1) col[i] = 1, dfs(dfs, i);

    int cnt = 0;
    for (int i = 1;i <= n;i++) if (col[i]) cnt++;

    int val = 1;
    while (vis[val]) val++;

    std::cout << cnt << " " << val << '\n';
    for (int i = 1;i <= n;i++)
        if (col[i])  std::cout << i << ' ';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }

}
