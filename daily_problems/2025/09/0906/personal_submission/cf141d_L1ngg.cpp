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
    int n, l;   std::cin >> n >> l;
    std::vector<a3> e;

    std::vector<int> pos;
    pos.push_back(0);
    pos.push_back(l);
    for (int i = 1;i <= n;i++) {
        int x, d, t, p; std::cin >> x >> d >> t >> p;
        e.push_back({ x - p,x + d,p + t });
        if (x >= p) pos.push_back(x - p), pos.push_back(x + d);
    }

    std::sort(pos.begin(), pos.end());
    int cnt = std::unique(pos.begin(), pos.end()) - pos.begin();

    std::vector<std::vector<a3>> adj(cnt);
    for (int i = 1;i < cnt;i++) {
        int d = pos[i] - pos[i - 1];
        adj[i].push_back({ 0,i - 1,d });
        adj[i - 1].push_back({ 0,i,d });
    }

    for (int i = 0;i < n;i++) {
        auto [x1, x2, t] = e[i];
        if (x1 < 0) continue;
        int no1 = std::lower_bound(pos.begin(), pos.begin() + cnt - 1, x1) - pos.begin();
        int no2 = std::lower_bound(pos.begin(), pos.begin() + cnt - 1, x2) - pos.begin();
        adj[no1].push_back({ i + 1,no2,t });
    }

    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({ 0,0 });
    std::vector<int> dis(cnt, inf);
    dis[0] = 0;
    std::vector<int> vis(cnt);
    std::vector<pii> pre(cnt);

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [eid, v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pre[v] = { eid,u };
                pq.push({ dis[v],v });
            }
        }
    }

    for (int i = 0;i < cnt;i++) {
        if (pos[i] == l) {
            std::cout << dis[i] << '\n';

            std::vector<int> ans;
            int cur = i;
            while (cur) {
                if (pre[cur].first)ans.push_back(pre[cur].first);
                cur = pre[cur].second;
            }
            std::reverse(ans.begin(), ans.end());
            std::cout << ans.size() << '\n';
            for (auto& x : ans) std::cout << x << " ";
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}