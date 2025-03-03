#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> adj(n);
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        e[u].push_back(i);
        e[v].push_back(i);
    }

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::ranges::sort(p, [&](int i, int j){ 
        return adj[i].size() < adj[j].size();
    });

    int cur = adj[p[n - 1 - k]].size();
    std::cout << cur << "\n";
    
    std::vector<int> ans(n - 1);
    auto dfs = [&](this auto &&self, int x, int now, int fa = -1) -> void {
        now -= 1;
        if (now == 0) {
            now = cur;
        }
        for (int i = 0; i < adj[x].size(); i++) {
            if (!ans[e[x][i]]) {
                ans[e[x][i]] = now;
                if (--now == 0) {
                    now = cur;
                }
            }
            if (adj[x][i] != fa) {
                self(adj[x][i], ans[e[x][i]], x);
            }
        }
    };  
    dfs(0, cur);

    for (int i = 0; i < n - 1; i++) {
        std::cout << ans[i] << " \n"[i == n - 2];
    }

    return 0;
}
