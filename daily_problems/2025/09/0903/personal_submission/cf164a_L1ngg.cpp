#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> a[i];

    std::vector adj(n + 1, std::vector<int>());
    std::vector radj(n + 1, std::vector<int>());
    for (int i = 1;i <= m;i++) {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    std::vector<int> vis1(n + 1), vis2(n + 1);
    auto dfs1 = [&](auto&& self, int u) ->void {
        vis1[u] = 1;
        for (auto v : adj[u]) {
            if (!vis1[v] && a[v] != 1)
                self(self, v);
        }
        };
    auto dfs2 = [&](auto&& self, int u) ->void {
        vis2[u] = 1;
        if (a[u] == 1) return;
        for (auto v : radj[u]) {
            if (!vis2[v])
                self(self, v);
        }
        };
    for (int i = 1;i <= n;i++) {
        if (a[i] == 1) dfs1(dfs1, i);
        if (a[i] == 2) dfs2(dfs2, i);
    }

    for (int i = 1;i <= n;i++)
        std::cout << (vis1[i] && vis2[i] ? 1 : 0) << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}