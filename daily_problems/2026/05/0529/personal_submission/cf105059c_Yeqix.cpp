#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, g;
    cin >> n >> m >> g;
    vector<vector<int>> edge(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int ans = 0;
    vector<int> vis(n + 1, -1);
    auto dfs = [&](auto&& dfs, int u, int fa) -> void {
        for (const auto& v : edge[u]) {
            if (v == fa) {
                continue;
            }
            int nxt = vis[u] ^ 1;
            if (vis[v] != -1 && vis[v] != nxt) {
                ans = 1;
                return;
            }
            if (vis[v] != -1) {
                continue;
            }
            vis[v] = nxt;
            dfs(dfs, v, u);
        }
    };
    vis[1] = 0;
    dfs(dfs, 1, 0);

    if (g == 2) {
        if (!ans) {
            cout << (vis[n] != vis[1]);
        } else {
            cout << 0;
        }
    } else {
        cout << 0;
    }
    return 0;
}
