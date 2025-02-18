#include <bits/stdc++.h>
// #include <ranges>
 
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
 
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++ i) std::cin >> a[i];

    std::vector<std::vector<std::pair<int, int>>> adj(n);

    for (int i = 1, fa, w; i < n; ++ i) {
        std::cin >> fa >> w;
        -- fa;
        adj[fa].emplace_back(i, w);
    }

    std::vector<i64> d(n);

    int res = n;

    auto dfs = [&](auto &&self, int u) -> void {
        -- res;
        for (auto &[v, w] : adj[u]) {
            d[v] = std::max(0LL, d[u]) + w;
            if (d[v] <= a[v])
                self(self, v);
        }
    };

    dfs(dfs, 0);

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