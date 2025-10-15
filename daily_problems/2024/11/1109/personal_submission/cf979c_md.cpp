// 1109
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, y;
    std::cin >> n >> x >> y;
    --x; --y;
    std::vector<std::vector<int>> paths(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        paths[u].push_back(v);
        paths[v].push_back(u);
    }

    std::vector<int> parents(n, -1);
    std::vector<i64> size(n, 1);
    auto dfs = [&](auto&& dfs, int cur, int p) -> void {
        parents[cur] = p;
        for (auto child : paths[cur]) {
            if (child == p) {
                continue;
            }
            dfs(dfs, child, cur);
            size[cur] += size[child];
        }
    };

    dfs(dfs, x, -1);

    int childOfX = y;
    while (parents[childOfX] != x) {
        childOfX = parents[childOfX];
    }
    i64 ans = 1ll * size[y] * (1ll * n - size[childOfX]);

    std::cout << 1ll * n * (n - 1) - ans << std::endl;

    return 0;
}