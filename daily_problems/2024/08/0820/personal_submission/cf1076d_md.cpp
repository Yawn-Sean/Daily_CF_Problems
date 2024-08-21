// 0820
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::tuple<int, int, int>> edges;
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u, --v;
        edges.emplace_back(u, v, w);
        graph[u].push_back(i);
        graph[v].push_back(i);
    }

    std::vector<i64> dist(n, 1e15);
    std::vector<int> toEdge(n);
    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!empty(pq)) {
        auto[d, cur] = pq.top();
        pq.pop();
        if (dist[cur] != d) {
            continue;
        }

        for (auto edge_idx : graph[cur]) {
            auto[u, v, w] = edges[edge_idx];
            int next = cur ^ u ^ v;
            if (dist[next] > dist[cur] + w) {
                dist[next] = dist[cur] + w;
                toEdge[next] = edge_idx;
                pq.push({dist[next], next});
            }
        }
    }

    std::vector<int> nodes(n);
    std::iota(begin(nodes), end(nodes), 0);
    std::sort(begin(nodes), end(nodes), [&](int a, int b) {
        return dist[a] < dist[b];
    });

    int cnt = std::min(k, n - 1);
    std::cout << cnt << "\n";
    for (int i = 1; i <= cnt; ++i) {
        std::cout << toEdge[nodes[i]] + 1 << " ";
    }

    return 0;
}