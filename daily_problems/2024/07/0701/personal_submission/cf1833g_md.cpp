// 0701
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> edges(n - 1);
    std::vector<std::vector<std::pair<int, int>>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        edges[i] = {u, v};
        tree[u].emplace_back(v, i);
        tree[v].emplace_back(u, i);
    }

    std::vector<int> siz(n, 1);
    std::vector<int> ret;
    auto dfs = [&](auto self, int cur, int parent) -> void {
        for (auto[next, idx] : tree[cur]) {
            if (next == parent) {
                continue;
            }
            self(self, next, cur);
            if (siz[next] == 0) {
                ret.push_back(idx);
            }
            siz[cur] += siz[next];
        }

        if (siz[cur] == 3) {
            siz[cur] = 0;
        }
    };

    dfs(dfs, 0, -1);

    if ((1 + size(ret)) * 3 != n) {
        std::cout << -1 << '\n';
        return;
    }

    std::cout << size(ret) << '\n';
    for (auto idx : ret) {
        std::cout << idx + 1 << '\n';
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}