#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL
#include "C:\Program Files\DEBUG\debug.h"
#else
#define debug(...) 114514
#define ps 114514
#endif

const int inf = 1e15;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    map<pair<int, int>, int> id;
    vector<vector<pair<int, int>>> mp(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
        id[{u, v}] = id[{v, u}] = i;
    }
    vector<int> dis(n + 1), vis(n + 1), pre(n + 1);
    auto dj = [&](int s) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;

        for (int i = 1; i <= n; i++)
            dis[i] = inf, vis[i] = 0;
        dis[s] = 0ll;
        q.push({dis[s], s});

        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (auto [v, w] : mp[u]) {
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
    };
    dj(1);
    vector<int> ans;
    fill(vis.begin(), vis.end(), 0);
    auto dfs = [&](auto self, auto u) -> void {
        for (auto [v, w] : mp[u]) {
            if (dis[u] + w != dis[v] || vis[v])
                continue;
            vis[v] = 1;
            if (ans.size() < k)
                ans.push_back(id[{u, v}]);
            self(self, v);
        }
    };
    vis[1] = 1;
    dfs(dfs, 1);
    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i << ' ';
    }
    return 0;
}
