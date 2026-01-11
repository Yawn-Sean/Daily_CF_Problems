#include <bits/stdc++.h>
using namespace std;

const int INF = 2000000000;

vector<int> shortest(const vector<vector<pair<int,int>>>& graph, int n) {
    vector<int> dist(n, INF);
    dist[0] = 0;

    // priority_queue of (distance, node), min-heap
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u] < d) continue;

        for (auto &e : graph[u]) {
            int v = e.first;
            int w = e.second;

            int nd = max(d, w);
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> path(n), rev(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;

        path[u].push_back({v, w});
        rev[v].push_back({u, w});
    }

    vector<int> d1 = shortest(path, n);
    vector<int> d2 = shortest(rev, n);

    for (int i = 0; i < n; ++i) {
        if (d2[i] > d1[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
