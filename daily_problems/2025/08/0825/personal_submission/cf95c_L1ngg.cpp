#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<i64, int>;
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
    std::vector adj(n, std::vector<pii>());
    int st, en; std::cin >> st >> en;
    st--, en--;
    for (int i = 1;i <= m;i++) {
        int u, v, w;    std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }

    std::vector dis(n, std::vector<i64>(n, INF));

    for (int i = 0;i < n;i++) {
        std::vector<int> vis(n);
        std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
        pq.push({ 0,i });
        dis[i][i] = 0;
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, w] : adj[u]) {
                if (dis[i][v] > d + w)
                {
                    dis[i][v] = d + w;
                    pq.push({ dis[i][v],v });
                }
            }
        }
    }

    std::vector<i64> t(n), c(n);
    for (int i = 0;i < n;i++)   std::cin >> t[i] >> c[i];

    std::vector<int> vis(n);
    std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
    pq.push({ 0,st });
    dis[st][st] = 0;
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (u == en) {
            std::cout << d;
            return;
        }

        if (vis[u]) continue;
        vis[u] = 1;

        for (int i = 0;i < n;i++)
            if (t[u] >= dis[u][i])
                pq.push({ c[u] + d,i });
    }
    std::cout << -1;
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