#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

// 图的邻接表
class Graph {
public:
    int V;
    vector<Edge> edges, backup;

    Graph(int V) {
        this->V = V;
    }

    void init(int k) {
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });
        backup = edges;
        for(auto&e: edges) e.weight = max(0, e.weight-k);
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    // 查找父节点
    int findParent(int parent[], int i) {
        if (parent[i] == i) return i;
        parent[i] = findParent(parent, parent[i]);
        return parent[i];
    }

    // 合并两个子集合
    void unionSets(int parent[], int x, int y) {
        parent[x] = y;
    }

    long long kruskalMST(int k) {
        int *parent = new int[V];
        for(int i=0; i<V; i++) parent[i] = i;

        vector<Edge> result;

        for (auto edge : edges) {
            int x = findParent(parent, edge.u);
            int y = findParent(parent, edge.v);

            if (x != y) {
                result.push_back(edge);
                unionSets(parent, x, y);
            }
        }

        long long res = 0;
        for (auto edge : result) {
            res += edge.weight;
        }

        delete[] parent;

        if(res > 0) return res;

        res = k - edges[0].weight;
        for (auto edge : backup) {
            res = min(res, abs((long long)edge.weight - k));
        }

        return res;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    Graph g(n);
    for(int i=0; i<m; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        g.addEdge(x-1, y-1, s);
    }
    g.init(k);
    cout << g.kruskalMST(k) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while(T --) solve();
	return 0;
}
