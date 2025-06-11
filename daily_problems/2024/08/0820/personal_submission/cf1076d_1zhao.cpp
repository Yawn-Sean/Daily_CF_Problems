#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long weight;
    int id;
};

class Graph {
public:
    int V;
    vector<vector<Edge>> adj;

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, long long weight, int id) {
        adj[u].push_back({v, weight, id});
        adj[v].push_back({u, weight, id});
    }

    void dijkstra(int source, int k, vector<int> &edges) {
        vector<long long> dist(V, numeric_limits<long long>::max());
        vector<int> path(V);
        vector<bool> visit(V);
        dist[source] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0ll, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if(visit[u]) continue;
            visit[u] = 1;

            if(u != source && edges.size() < k) {
                edges.push_back(path[u]);
                if(edges.size() == k) return;
            }

            for (const auto& edge : adj[u]) {
                int v = edge.to;
                long long weight = edge.weight;
                int id = edge.id;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                    path[v] = id;
                }
            }
        }

        return;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    Graph g(n);
    for(int i=1; i<=m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u-1, v-1, (long long)w, i);
    }
    vector<int> res;
    g.dijkstra(0, k, res);
    cout << res.size() << endl;
    for(int i: res) cout << i << ' ';
    cout << endl;
}
