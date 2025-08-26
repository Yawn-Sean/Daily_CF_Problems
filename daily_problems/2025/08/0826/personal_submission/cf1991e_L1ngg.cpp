#include <bits/stdc++.h>
void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector adj(n + 1, std::vector<int>());
    for (int i = 1;i <= m;i++) {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> col(n + 1, -1), c0, c1;
    int f = 0;
    auto dfs = [&](auto&& self, int u)->void {
        if (col[u] == 1) c1.push_back(u);
        else  c0.push_back(u);
        for (auto v : adj[u])
        {
            if (col[v] == -1) {
                col[v] = col[u] ^ 1;
                self(self, v);
            }if (col[v] == col[u]) f = 1;
        }
        };

    col[1] = 0;
    dfs(dfs, 1);

    if (f) {
        std::cout << "Alice" << std::endl;
        for (int i = 1;i <= n;i++)
        {
            std::cout << "1 2" << std::endl;
            int num1, num2; std::cin >> num1 >> num2;
        }
        return;
    }
    std::cout << "Bob" << std::endl;
    for (int i = 1;i <= n;i++) {
        int num1, num2; std::cin >> num1 >> num2;
        if ((num1 == 1 || num2 == 1) && c0.size())
        {
            int u = c0.back();
            c0.pop_back();
            std::cout << u << " " << 1 << std::endl;
        }
        else if ((num1 == 2 || num2 == 2) && c1.size()) {
            int u = c1.back();
            c1.pop_back();
            std::cout << u << " " << 2 << std::endl;
        }
        else if (c0.size()) {
            int u = c0.back();
            c0.pop_back();
            std::cout << u << " " << 3 << std::endl;
        }
        else if (c1.size()) {
            int u = c1.back();
            c1.pop_back();
            std::cout << u << " " << 3 << std::endl;
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        // std::cout << '\n';
    }
}