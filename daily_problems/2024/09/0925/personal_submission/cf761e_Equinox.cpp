#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

constexpr int N = 2E5;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1, u, v; i < n; ++ i) {
        std::cin >> u >> v;
        -- u, -- v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (adj[u].size() == 5 || adj[v].size() == 5) {
            std::cout << "NO\n";
            return;
        }
    }

    std::vector<bool> vis(n);
    std::vector<std::pair<int, int>> ans(n);
    ans[0] = {0, 0};
    vis[0] = true;
    constexpr int dir[]{ -1, 0, 1, 0, -1 };
    std::queue<std::tuple<int, int, int>> q;
    q.emplace(0, -1, 1 << 29);


    while (q.size()) {
        auto [u, d, len] = q.front();
        q.pop();

        len /= 2;
        int curd = 0;

        for (int v : adj[u]) {
            if (vis[v]) continue;

            if (curd == d)
                ++ curd;
            int x = ans[u].first + dir[curd] * len, y = ans[u].second + dir[curd + 1] * len;
            
            ans[v] = {x, y};
            
            vis[v] = true;
            q.emplace(v, curd ^ 2, len);
            ++ curd;
        }
    }

    std::cout << "YES\n";
    for (auto &[x, y] : ans)
        std::cout << x << ' ' << y << '\n';

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}