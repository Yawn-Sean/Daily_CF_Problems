// 0610
#include <bits/stdc++.h>
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n;
    std::cin >> n;
    std::vector<int> parent(n + 1);
    std::vector<int> cnt(n + 1);
    std::vector<std::vector<int>> tree(n + 1);
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        int p;
        std::cin >> p >> cnt[i];
        if (p == 0) {
            root = i;
        } else {
            tree[p].push_back(i);
        }
    }
 
    bool cando {true};
    auto dfs = [&](auto self, int cur) -> std::vector<int> {
        std::vector<int> subtree_nodes;
 
        for (auto next : tree[cur]) {
            auto child_ret = self(self, next);
            subtree_nodes.insert(end(subtree_nodes), begin(child_ret), end(child_ret));
        }
 
        if (size(subtree_nodes) < cnt[cur]) {
            cando = false;
            return {};
        }
 
        subtree_nodes.insert(begin(subtree_nodes) + cnt[cur], cur);
        return subtree_nodes;
    };
 
 
    auto nodes = dfs(dfs, root);
    if (cando) {
        std::cout << "YES\n";
        std::vector<int> ans(n + 1);
        for (int i = 0; i < n; ++i) {
            ans[nodes[i]] = i + 1;
        }
        for (int i = 1; i <= n; ++i) {
            std::cout << ans[i] << " \n"[i == n];
        }
    } else {
        std::cout << "NO\n";
    }
 
    return 0;
}