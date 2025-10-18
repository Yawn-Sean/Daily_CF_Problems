#include <bits/stdc++.h>

using namespace std;
constexpr double INF = 1e15;

int main() {
    int n, m, T;
    scanf("%d%d%d", &n, &m, &T);
    vector<vector<tuple<int, int, int>>> g(n, vector<tuple<int, int, int>>());
    for (int i = 0, u, v, l, c; i < m; i++) {
        scanf("%d%d%d%d", &u, &v, &l, &c);
        g[u - 1].emplace_back(v - 1, l, c);
        g[v - 1].emplace_back(u - 1, l, c);
    }
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    vector<double> dist(n, INF);
    dist[0] = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [u_cst, u] = q.top(); q.pop();
        if (dist[u] < u_cst) continue;
        for (auto& [v, l, c] : g[u]) {
            double cost = sqrt(1.0 * l * c);
            if (dist[v] > u_cst + cost) {
                dist[v] = u_cst + cost;
                q.emplace(dist[v], v);
            }
        }
    }
    printf("%.8f\n", dist[n - 1] * dist[n - 1] / T);
    return 0;
}

