// 0717
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, h, t;
    std::cin >> n >> m >> h >> t;

    std::vector<std::vector<int>> graph(n);
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        edges.emplace_back(u, v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (auto [u, v] : edges) {
        auto check = [&](int u, int v) {
            if (size(graph[u]) <= h || size(graph[v]) <= t) {
                return false;
            } 

            std::vector<int> score(n);
            score[u] = std::numeric_limits<int>::min();
            score[v] = std::numeric_limits<int>::min();
            for (auto x : graph[u]) {
                score[x] += 1;
            }
            for (auto y : graph[v]) {
                score[y] += 2;
            }

            if (std::count_if(begin(score), end(score), [&](int x) { return x > 0; }) < h + t) {
                return false;
            }

            auto filter_idx_by_val = [&](int val) {
                std::vector<int> ret;
                for (int i = 0; i < n; ++i) {
                    if (score[i] == val) {
                        ret.push_back(i);
                    }
                }
                return ret;
            };
            auto v1 = filter_idx_by_val(1);
            auto v2 = filter_idx_by_val(2);
            auto v3 = filter_idx_by_val(3);

            std::cout << "YES\n" << u + 1 << " " << v + 1 << "\n";
            int idx3 = 0;
            while (idx3 < size(v3) && ssize(v1) < h) {
                v1.emplace_back(v3[idx3++]);
            }
            while (idx3 < size(v3) && ssize(v2) < t) {
                v2.emplace_back(v3[idx3++]);
            }
            
            for (int i = 0; i < h; ++i) {
                std::cout << v1[i] + 1 << " ";
            }
            std::cout << "\n";
            for (int i = 0; i < t; ++i) {
                std::cout << v2[i] + 1 << " ";
            }
            std::cout << "\n";
            return true;
        };

        if (check(u, v) || check(v, u)) {
            return 0;
        }
    }
    std::cout << "NO\n";

    return 0;
}