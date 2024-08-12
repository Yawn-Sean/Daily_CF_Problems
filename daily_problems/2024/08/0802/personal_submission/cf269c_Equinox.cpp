#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1e-9;

constexpr int N = 1005;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::array<int, 3>>> adj(n);
    std::vector<int> cap(n);
    for (int i = 1, u, v, c; i <= m; ++ i) {
        std::cin >> u >> v >> c;
        -- u, -- v;
        adj[u].push_back({v, c, i});
        adj[v].push_back({u, c, -i});
        cap[u] += c, cap[v] += c;
    }

    for (auto& x : cap)
        x /= 2;

    std::vector<int> ans(m, -1);

    auto dfs = [&](auto&& self, int u) -> void {
        for (auto& [v, c, i] : adj[u]) {
            if (~ans[abs(i) - 1]) continue;
            ans[abs(i) - 1] = i > 0 ? 0 : 1;
            if (!(cap[v] -= c)) {
                if (v + 1 != n)
                    self(self, v);
            }
        }
    };

    dfs(dfs, 0);

    for (int x : ans)
        std::cout << x << '\n';
}

auto FIO = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}