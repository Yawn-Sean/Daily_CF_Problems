#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);

    for (int i = 0, u, v; i < m; ++ i) {
        std::cin >> u >> v;
        -- u, -- v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> f(n, 1);
    for (int i = 0; i < n; ++ i)
        for (int j : adj[i])
            if (j < i)
                f[i] = std::max(f[i], f[j] + 1);

    i64 res = 0;

    for (int i = 0; i < n; ++ i)
        res = std::max<size_t>(res, f[i] * adj[i].size());

    std::cout << res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}