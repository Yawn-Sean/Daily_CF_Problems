#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
去掉一条边，使得存在路径的顶点对最少
那么就是尽可能让去掉的边的两边的点数接近，这样最好
有可能去掉某条边并不能让图变成两个连通块，这种就没用
可以使用 tarjan 求割边
如何求一条边的两边有多少点？
假如 (u, v) 是割边，则断开 (u, v) 之后，u 可达的其他点肯定不是 v 可达的
割边的两个端点 u, v 是否可能互相都不是对方的祖先？不可能的，不然这个边就不是割边了
预处理一个 dfs 树，预处理子树大小
对于 (u, v) 割边，假如 v 是 u 的孩子，则更新 n * (n - 1) / 2 - sz[v] * (n - sz[v])
*/

class Graph {
    long long V; // 顶点数
    vector<vector<int>> adj; // 邻接表
    int time; // DFS时间戳

    void bridgeUtil(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<long long>& size, vector<vector<long long>>& bridges) {
        disc[u] = low[u] = ++time;
        size[u] = 1; // 初始化大小为1（包含自己）

        for (int v : adj[u]) {
            if (disc[v] == -1) { // v未被访问
                parent[v] = u;
                bridgeUtil(v, disc, low, parent, size, bridges);
                
                // 回溯时更新子树大小
                size[u] += size[v];
                
                // 更新low值
                low[u] = min(low[u], low[v]);
                
                // 检查是否是桥
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v, size[v], V - size[v]});
                }
            }
            else if (v != parent[u]) { // 处理回边
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    Graph(int vertices) : V(vertices), adj(vertices), time(0) {}
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void findBridges() {
        vector<int> disc(V, -1); // 发现时间
        vector<int> low(V, -1);  // 最低可达祖先
        vector<int> parent(V, -1); // 父节点
        vector<long long> size(V, 0);  // 子树大小
        vector<vector<long long>> bridges; // 存储桥及其连通分量大小
        
        time = 0;
        
        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                bridgeUtil(i, disc, low, parent, size, bridges);
            }
        }
        
        long long res = 0;
        for (int i = 0; i < bridges.size(); i++) {
            int u = bridges[i][0], v = bridges[i][1];
            if (parent[u] == v) {
                res = max(res, size[u] * (V - size[u]));
            } else {
                res = max(res, size[v] * (V - size[v]));
            }
        }
        cout << V * (V - 1) / 2 - res << "\n";
    }
};

int n, m;

void solve() {
    cin >> n >> m;
    Graph g(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u - 1, v - 1);
        g.addEdge(v - 1, u - 1);
    }
    
    g.findBridges();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
