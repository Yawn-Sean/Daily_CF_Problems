// 0720
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    --s; --t;
    std::vector<std::vector<int>> graph(n);
    std::vector<std::vector<int>> connected(n, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        connected[u][v] = connected[v][u] = 1;
    }

    std::vector<int> dist_to_s(n, -1), dist_to_t(n, -1);
    auto bfs = [&](int start, std::vector<int>& dist) {
        std::queue<int> q;
        q.push(start);
        dist[start] = 0;
        while (!empty(q)) {
            auto cur = q.front();
            q.pop();
            for (auto next : graph[cur]) {
                if (dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }
    };

    bfs(s, dist_to_s);
    bfs(t, dist_to_t);
    const auto dist = dist_to_s[t];

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (connected[i][j]) {
                continue;
            }
            if (dist_to_s[i] + 1 + dist_to_t[j] >= dist && dist_to_s[j] + 1 + dist_to_t[i] >= dist) {
                ++ret;
            }
        }
    }

    std::cout << ret << '\n';

    return 0;
}