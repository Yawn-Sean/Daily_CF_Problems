#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    vector<vector<int>> edge(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<int> dist(n + 1, m + 10);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> que;
    que.push({dist[1] = 0, 1});
    while (!que.empty()) {
        auto [dis, u] = que.top();
        que.pop();
        if (dis != dist[u]) {
            continue;
        }
        for (const auto& v : edge[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                que.push({dist[v], v});
            }
        }
    }

    set<array<int, 2>, greater<array<int, 2>>> q;
    vector<bitset<8000>> bt(n + 1);
    for (int i = 1; i <= k; i++) {
        q.insert({dist[a[i]], a[i]});
        bt[a[i]][i - 1] = 1;
    }

    while (!q.empty()) {
        auto [dis, u] = *q.begin();
        q.erase(q.begin());
        for (const auto& v : edge[u]) {
            if (dist[v] == dis - 1) {
                bt[v] |= bt[u];
                q.insert({dist[v], v});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (bt[i].count() == k) {
            ans = max(ans, dist[i]);
        }
    }
    cout << ans;
    return 0;
}