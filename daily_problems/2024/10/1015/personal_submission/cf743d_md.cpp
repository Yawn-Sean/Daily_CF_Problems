// 1015
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> nodes(n);
    std::vector<std::vector<int>> tree(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nodes[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    std::vector<i64> dp(n, LONG_LONG_MIN);
    i64 ans = LONG_LONG_MIN;

    auto dfs = [&](auto&& self, int u, int p) -> i64 {
        i64 sum = 0;
        i64 subTree1 = LONG_LONG_MIN;
        i64 subTree2 = LONG_LONG_MIN;
        for (auto next : tree[u]) {
            if (next == p) {
                continue;
            }

            sum += self(self, next, u);
            auto subtreeMax = dp[next];
            if (subTree1 < subtreeMax) {
                subTree2 = subTree1;
                subTree1 = subtreeMax;
            } else if (subTree2 < subtreeMax) {
                subTree2 = subtreeMax;
            }
        }

        if (subTree1 != LONG_LONG_MIN && subTree2 != LONG_LONG_MIN) {
            ans = std::max(ans, subTree1 + subTree2);
        }

        i64 curSubTree = nodes[u] + sum;
        dp[u] = std::max({dp[u], curSubTree, subTree1});
        return curSubTree;
    };

    dfs(dfs, 0, -1);

    if (ans == LONG_LONG_MIN) {
        std::cout << "Impossible\n";
    } else {
        std::cout << ans << '\n';
    }

    return 0;
}