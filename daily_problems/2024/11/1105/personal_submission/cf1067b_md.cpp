// 1105
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::set<int>> graph(n);
    std::vector<int> degrees(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;

        graph[u].insert(v);
        graph[v].insert(u);
        ++degrees[u];
        ++degrees[v];
    }

    if (n == 1) {
        std::cout << "No\n";
        return 0;
    }

    std::queue<int> leaves;
    for (int i = 0; i < n; ++i) {
        if (degrees[i] == 1) {
            leaves.push(i);
        }
    }

    int level = 0;
    while (size(leaves) > 1) {
        auto siz = std::ssize(leaves);
        std::unordered_map<int, int> deltas;
        for (int i = 0; i < siz; ++i) {
            auto u = leaves.front();
            leaves.pop();
            degrees[u] = 0;
            for (auto v : graph[u]) {
                if (degrees[v] > 0) {
                    --degrees[v];
                    graph[v].erase(u);
                    ++deltas[v];
                    if (degrees[v] == 1) {
                        leaves.push(v);
                    }
                }
            }
        }

        if (any_of(begin(deltas), end(deltas), [&](auto&& vals) { return vals.second < 3; })) {
            std::cout << "No\n";
            return 0;
        }

        ++level;
    }

    if (ssize(leaves) == 1 && level == k) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}