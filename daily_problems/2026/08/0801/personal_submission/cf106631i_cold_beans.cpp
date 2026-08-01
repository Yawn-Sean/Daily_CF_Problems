#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize(3)

void run_case() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    vector<set<pair<int, int>>> edges(n+1);
    while (m--) {
        int u, v; cin >> u >> v;

        if (edges[u].contains({v, 1})) {
            edges[u].erase({v, 1}); edges[u].insert({v, 2});
        }
        else edges[u].insert({v, 1});

        if (edges[v].contains({u, 1})) {
            edges[v].erase({u, 1}); edges[v].insert({u, 2});
        }
        else edges[v].insert({u, 1});
    }

    vector<int> dis(n+1, 1e13); dis[b] = 0;
    queue<int> q; q.push(b); vector<int> vis(n+1); vis[b] = 1;
    vector<int> light(n+1);

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto [to, w]: edges[u]) {
            if (vis[to]) continue;
            if (w == 2) {
                dis[to] = dis[u] + 1;
                q.push(to);
                vis[to] = 1;
            }
            else if (w == 1) {
                light[to]++;
                if (light[to] == 2) {
                    dis[to] = dis[u] + 1;
                    q.push(to);
                    vis[to] = 1;
                }
            }
        }
    }

    if (!vis[a]) cout << -1;
    else cout << dis[a];
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run_case();
        cout << '\n';
    }
    return 0;
}