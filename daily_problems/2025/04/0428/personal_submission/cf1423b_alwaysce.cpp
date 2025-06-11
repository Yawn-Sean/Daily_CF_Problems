#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class HopcroftKarp {
public:
    int n, m;
    vector<vector<int>> adj; 
    vector<int> pairU, pairV, dist;

    HopcroftKarp(int n, int m) : n(n), m(m), adj(n) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> Q;
        dist.assign(n, -1);
        for (int u = 0; u < n; ++u) {
            if (pairU[u] == -1) {
                dist[u] = 0;
                Q.push(u);
            }
        }
        bool found = false;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int v : adj[u]) {
                if (pairV[v] == -1) {
                    found = true;
                } else if (dist[pairV[v]] == -1) {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
        return found;
    }

    bool dfs(int u) {
        for (int v : adj[u]) {
            if (pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int maxMatching() {
        pairU.assign(n, -1);
        pairV.assign(m, -1);
        dist.resize(n);
        int matching = 0;
        while (bfs()) {
            for (int u = 0; u < n; ++u) {
                if (pairU[u] == -1 && dfs(u)) {
                    ++matching;
                }
            }
        }
        return matching;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m; 
    int min_d = 1e9+7, max_d = 0;
    vector<tuple<int,int,int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        --u; --v;
        edges.push_back({u, v, d});
        min_d = min(min_d, d);
        max_d = max(max_d, d);
    }

    int left = min_d, right = max_d + 1;
    int ans = -1;
    while (left < right) {
        int mid = (left + right) / 2;
        HopcroftKarp hk(n, m);
        for (auto [u, v, d] : edges) {
            if (d <= mid) {
                hk.addEdge(u, v);
            }
        }
        int e = hk.maxMatching();
        if (e == n) {
            ans = mid;
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
