#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    long double T;
    if (!(cin >> n >> m >> T)) return 0;

    vector<vector<pair<int, long double>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long l, c;
        cin >> u >> v >> l >> c;
        long double w = sqrtl((long double)l * (long double)c); // w_e = sqrt(l*c)
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    const long double INF = 1e300L;
    vector<long double> dist(n + 1, INF);
    vector<char> vis(n + 1, 0);
    priority_queue<pair<long double,int>, vector<pair<long double,int>>, greater<pair<long double,int>>> pq;

    dist[1] = 0;
    pq.push({0.0L, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        if (u == n) break;
        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    long double D = dist[n];
    long double ans = (D * D) / T;
    cout.setf(std::ios::fixed); 
    cout << setprecision(10) << (double)ans << "\n";
    return 0;
}
