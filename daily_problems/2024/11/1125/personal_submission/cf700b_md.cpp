// 1125
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> nodes(n, 0);
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < 2 * k; ++i) {
        int x;
        std::cin >> x;
        nodes[x - 1] = 1;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    i64 ret = 0;
    auto dfs = [&](auto&& dfs, int cur, int parent) -> int {
        int cnt = nodes[cur];
        for (auto next : graph[cur]) {
            if (next == parent) {
                continue;
            }
            cnt += dfs(dfs, next, cur);
        }
        ret += std::min(cnt, 2 * k - cnt);
        return cnt;
    };

    dfs(dfs, 0, -1);
    std::cout << ret << '\n';

    return 0;
}