#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1e9 + 1;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<int> a(n);
        for (auto& x : a) {
            scanf("%d", &x);
        }
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0, x, y, w; i < m; i++) {
            scanf("%d %d %d", &x, &y, &w);
            x -= 1;
            y -= 1;
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        for (int i = 0; i < n; i++) {
            q.emplace(a[i], i);
        }
        while (!q.empty()) {
            auto [d, u] = q.top(); q.pop();
            if (a[u] == d) {
                for (auto& [v, w] : g[u]) {
                    if (a[v] > d + w) {
                        a[v] = d + w;
                        q.emplace(a[v], v);
                    }
                }
            }
        }
        vector<int> dist(n, INF);
        dist[0] = 0;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [d, u] = q.top(); q.pop();
            if (dist[u] == d) {
                for (auto& [v, w] : g[u]) {
                    if (dist[v] > d + w && d + w <= a[v]) {
                        dist[v] = d + w;
                        q.emplace(dist[v], v);
                    }
                }
            }
        }
        if (dist[n - 1] < INF) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

