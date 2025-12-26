#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)1e15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> path(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        path[u].push_back({v, w});
    }
    vector<vector<ll>> dis(3, vector<ll>(n, INF));
    dis[0][0] = 0;

    priority_queue<tuple<ll,int,int>,
                   vector<tuple<ll,int,int>>,
                   greater<tuple<ll,int,int>>> pq;

    pq.emplace(0, 0, 0);

    while (!pq.empty()) {
        auto [d, u, cur] = pq.top();
        pq.pop();

        if (dis[cur][u] != d) continue;

        if (cur == 0) {
            for (auto [v, w] : path[u]) {
                if (dis[0][v] > d + w) {
                    dis[0][v] = d + w;
                    pq.emplace(dis[0][v], v, 0);
                }
                if (dis[1][v] > d + w / 2) {
                    dis[1][v] = d + w / 2;
                    pq.emplace(dis[1][v], v, 1);
                }
            }
        }
        else if (cur == 1) {
            for (auto [v, w] : path[u]) {
                if (dis[2][v] > d + w / 2) {
                    dis[2][v] = d + w / 2;
                    pq.emplace(dis[2][v], v, 2);
                }
            }
        }
        else {
            for (auto [v, w] : path[u]) {
                if (dis[2][v] > d + w) {
                    dis[2][v] = d + w;
                    pq.emplace(dis[2][v], v, 2);
                }
            }
        }
    }

    cout << min(dis[1][n - 1], dis[2][n - 1]) << "\n";
    return 0;
}
