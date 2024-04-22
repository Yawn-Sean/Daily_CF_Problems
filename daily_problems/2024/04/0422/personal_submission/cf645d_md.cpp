#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u; int v;
        cin >> u >> v;
        --u; --v;
        edges.emplace_back(u, v);
    }
    
    vector<int> indegree(n, 0);
    vector<vector<int>> graph(n);
    auto cando = [&](int limit) -> bool {
        indegree.assign(n, 0);
        graph.assign(n, vector<int>());
        for (int i = 0; i < limit; ++i) {
            auto[u, v] = edges[i];
            ++indegree[v];
            graph[u].push_back(v);
        }

        deque<int> zero_degree_nodes;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                zero_degree_nodes.push_back(i);
            }
        }

        while (!empty(zero_degree_nodes)) {
            if (size(zero_degree_nodes) > 1) {
                return false;
            }
            auto cur = zero_degree_nodes.front();
            zero_degree_nodes.pop_front();
            for (auto& nxt : graph[cur]) {
                --indegree[nxt];
                if (indegree[nxt] == 0) {
                    zero_degree_nodes.push_back(nxt);
                }
            }
        }
        return true;
    };

    int lo = 1;
    int hi = m;
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;
        if (cando(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    if (cando(lo)) {
        cout << lo << '\n';
    } else if (cando(hi)) {
        cout << hi << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}