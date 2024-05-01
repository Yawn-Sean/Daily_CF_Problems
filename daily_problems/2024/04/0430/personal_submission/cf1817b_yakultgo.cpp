#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 0; u < n; u++) {
        if (adj[u].size() >= 4) {
            std::queue<std::pair<int, int>> q;
            std::vector<std::array<int, 2>> s(n, {-1, -1});
            std::vector<std::array<std::pair<int, int>, 2>> pre(n);
            for (auto v : adj[u]) {
                s[v][0] = v;
                pre[v][0] = {u, 0};
                q.emplace(v, 0);
            }
            while (!q.empty()) {
                auto [x, t] = q.front();
                q.pop();

                for (auto y : adj[x]) {
                    if (y != u) {
                        if (s[y][0] == -1) {
                            s[y][0] = s[x][t];
                            pre[y][0] = {x, t};
                            q.emplace(y, 0);
                        } else if (s[y][1] == -1 && s[y][0] != s[x][t]) {
                            s[y][1] = s[x][t];
                            pre[y][1] = {x, t};
                            q.emplace(y, 1);
                        }
                    } else if (t == 1) {
                        std::cout << "YES\n";
                        std::vector<bool> vis(n);
                        std::vector<std::pair<int, int>> ans;
                        ans.emplace_back(u + 1, x + 1);
                        while (x != u) {
                            vis[x] = true;
                            auto [y, q] = pre[x][t];
                            ans.emplace_back(x + 1, y + 1);
                            std::tie(x, t) = std::pair(y, q);
                        }

                        int k = 0;
                        for (auto v : adj[u]) {
                            if (!vis[v] && k < 2) {
                                ans.emplace_back(u + 1, v + 1);
                                k++;
                            }
                        }

                        std::cout << ans.size() << "\n";
                        for (auto [x, y] : ans) {
                            std::cout << x << " " << y << "\n";
                        }

                        return;
                    }
                }
            }
        }
    }
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}