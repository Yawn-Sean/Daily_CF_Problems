// 0612
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        graph[x].push_back(y);
    }

    std::vector<std::vector<std::pair<int, int>>> edge_from(n);
    std::vector<std::vector<std::pair<int, int>>> edge_to(n);
    auto bfs = [&](int start) -> void {
        std::vector<int> dist(n, -1);
        std::queue<int> q;
        q.push(start);
        dist[start]= 0;

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

        for (int i = 0; i < n; ++i) {
            if (dist[i] > 0) {
                edge_from[start].push_back({dist[i], i});
                edge_to[i].push_back({dist[i], start});
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        bfs(i);
    }

    for(int i = 0; i < n; ++i) {
        std::ranges::sort(edge_from[i], std::greater<>());
        std::ranges::sort(edge_to[i], std::greater<>());
    }

    int tour_dis = 0;
    std::vector<int> cities{-1, -1, -1, -1};
    for (int b = 0; b < n; ++b) {
        for (auto[dist_ab, a] : edge_to[b] | std::views::take(3)) {
            if (dist_ab <= 0) { continue; }
            for (auto[dist_bc, c] : edge_from[b]) {
                if (dist_bc <= 0 || c == a) { continue; }
                for (auto[dist_cd, d] : edge_from[c] | std::views::take(3)) {
                    if (dist_cd <= 0 || d == a || d == b) { continue; }
                    if (tour_dis < dist_ab + dist_bc + dist_cd) {
                        tour_dis = dist_ab + dist_bc + dist_cd;
                        cities = {a, b, c, d};
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        cout << cities[i] + 1 << " \n"[i == 3];
    }
    return 0;
}