#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);
    std::set<std::pair<int, int>> ans;
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if (x != y) {
            ans.insert({x + 1, y + 1});
        }
    }

    auto bfs = [&](int s) {
        std::vector<int> dist(n, -1);
        std::queue<int> q;
        q.push(s);
        dist[s] = 0;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            for (auto y : adj[x]) {
                if (dist[y] == -1) {
                    q.push(y);
                    dist[y] = dist[x] + 1;
                }
            }
        }
        return dist;
    };

    std::vector<std::vector<int>> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = bfs(i);
    }

    
    for (int x = 0; x < n; x++) {
        for (int y = x + 1; y < n; y++) {
            if (d[x][y] == 2) {
                ans.insert({x + 1, y + 1});
            }
        }
    }
    std::cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        std::cout << x << " " << y << "\n";
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
