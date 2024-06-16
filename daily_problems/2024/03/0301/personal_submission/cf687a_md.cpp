// 0301
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<int> colors(n, -1);
    auto dfs = [&](auto self, int cur, int parent) -> bool {
        bool ret = true;
        for (auto next : graph[cur]) {
            if (next == parent) {
                continue;
            }

            if (colors[next] == -1) {
                colors[next] = colors[cur] ^ 1;
                if (!self(self, next, cur)) {
                    ret = false;
                }
            } else if (colors[next] == colors[cur]) {
                ret = false;
            }
        }

        return ret;
    };

    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) {
            colors[i] = 0;
            auto ret = dfs(dfs, i, -1);
            if (!ret) {
                std::cout << "-1\n";
                return 0;
            }
        }
    }

    auto ones = std::count(begin(colors), end(colors), 1);
    std::cout << ones << '\n';
    for (int i = 0; i < n; ++i) {
        if (colors[i] == 1) {
            std::cout << i + 1 << ' ';
        }
    }
    std::cout << '\n';
    std::cout << n - ones << '\n';
    for (int i = 0; i < n; ++i) {
        if (colors[i] == 0) {
            std::cout << i + 1 << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}