// 0710
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
    }

    auto check = [&](int cur) {
        std::vector<int> cnt(n);
        for (int nxt : graph[cur]) {
            for (int nnxt : graph[nxt]) {
                ++cnt[nnxt];
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (i == cur) {
                continue;
            }
            ret += cnt[i] * (cnt[i] - 1) / 2;
        }
        return ret;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += check(i);
    }
    std::cout << ans << '\n';

    return 0;
}