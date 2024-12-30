// 0604
#include <bits/stdc++.h>
 
using i64 = long long;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n;
    std::cin >> n;
 
    std::vector<std::tuple<int, int, int>> points;
    points.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x, y, d;
        std::cin >> x >> y >> d;
        points.emplace_back(x, y, d);
    }
 
    std::vector<std::vector<int>> graph(n); 
    for (int i = 0; i < n; ++i) {
        auto[x1, y1, d1] = points[i];
        for (int j = 0; j < i; ++j) {
            auto[x2, y2, d2] = points[j];
            i64 r = d1 + d2;
            i64 dx = x1 - x2;
            i64 dy = y1 - y2;
            if (r * r == dx * dx + dy * dy) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
 
    std::vector<int> colors(n, -1);    
    auto cando = [&](int i) {
        std::array<int, 2> cnts{1, 0};
        colors[i] = 0;
        auto dfs = [&](auto self, int u) -> bool {
            auto ret = true;
            for (auto v : graph[u]) {
                if (colors[v] == -1) {
                    colors[v] = colors[u] ^ 1;
                    cnts[colors[v]]++;
                    if (!self(self, v)) {
                        // Don't break, continue checking the other nodes
                        ret = false;
                    }
                } else if (colors[v] == colors[u]) {
                    // Don't break, continue checking the other nodes
                    ret = false;
                }
            }
            return ret;
        };

        return dfs(dfs, i) && cnts[0] != cnts[1];
    };
 
    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) {
            if (cando(i)) {
                std::cout << "YES\n";
                return 0;
            }
        }
    }
    std::cout << "NO\n";
 
    return 0;
}