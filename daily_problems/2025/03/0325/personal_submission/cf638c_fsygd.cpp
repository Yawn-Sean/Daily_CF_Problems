#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int main() {
    scanf("%d", &n);
    vector<int> colors(n);
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<pair<int, int>> edges(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].emplace_back(i);
        graph[v].emplace_back(i);
        edges[i] = make_pair(u, v);
    }

    for (int i = 1; i <= n; ++i) m = max(m, int(graph[i].size()));
    vector<vector<int>> schedule(m + 1, vector<int>());
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int colored = 0;
        for (const auto& edge: graph[u]) colored = max(colored, colors[edge]);
        int color = 0;
        for (const auto& edge: graph[u])
            if (!colors[edge]) {
                if (++color == colored) ++color;
                colors[edge] = color;
                schedule[color].emplace_back(edge);
                q.push(edges[edge].first + edges[edge].second - u);
            }
    }
    printf("%d\n", m);
    for (int i = 1; i <= m; ++i) {
        printf("%d", schedule[i].size());
        for (const auto& edge: schedule[i]) printf(" %d", edge);
        printf("\n");
    }
    return 0;
}