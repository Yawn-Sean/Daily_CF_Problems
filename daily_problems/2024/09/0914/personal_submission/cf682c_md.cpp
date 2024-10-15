// 0914
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<i64> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::vector<std::vector<std::pair<int, i64>>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        tree[u - 1].emplace_back(i + 1, v);
        tree[i + 1].emplace_back(u - 1, v);
    }

    std::vector<int> siz(n);
    auto cnt_siz = [&](auto self, int u, int p) -> void {
        siz[u]++;
        for (auto [v, w] : tree[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
            siz[u] += siz[v];
        }
    };
    cnt_siz(cnt_siz, 0, -1);

    int ret{ 0 };
    auto dfs = [&](auto self, int u, int p, i64 prefix) -> void {
        if (prefix > nums[u]) {
            ret += siz[u];
            return;
        }

        for (auto [v, w] : tree[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u, std::max(0ll, prefix + w));
        }
    };

    dfs(dfs, 0, -1, 0ll);
    std::cout << ret << '\n';

    return 0;
}