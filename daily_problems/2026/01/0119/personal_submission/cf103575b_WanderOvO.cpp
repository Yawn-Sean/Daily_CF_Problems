#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAXN = 300005;
const int LOGN = 21; 
const int INF = 1e9;

/*
求生成树，其中包含偶数条奇数边是否可行
不妨先把边权都变成 0 和 1
图保证是连通的
无脑求最小生成树，能把 0 尽量算上，但是可能会导致 1 的个数是奇数
这个时候枚举没被选的 1 边，加入到树中，形成一个环，只要这个环里面有 0，就可以替换掉调整成偶数
如何判断有没有 0？考虑加入的是 (u, v)
则考虑 u 到 v 路径上的 min 是不是 0，倍增搞一下
是的话，遍历，找到这条边，替换掉即可
或者枚举没被选的 0 边，看看环上存不存在 1 边，即 max = 1，存在的话替换即可(没必要，因为 kruskal 的过程中就告诉你了，0加入肯定是全 0 环)

手废了，思路是自己写的，代码是 AI 根据思路帮我打黑工写的
*/

struct Edge {
    int u, v, w, id; 
    bool operator<(const Edge& other) const {
        if (w != other.w) {
            return w < other.w; 
        }
        return id < other.id;
    }
};

struct DSU {
    vector<int> fa;
    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            fa[fx] = fy;
            return true;
        }
        return false;
    }
};

struct Node {
    int v, w, id;
};
vector<Node> adj[MAXN];

int up[MAXN][LOGN];    
int min_w[MAXN][LOGN];   
int min_id[MAXN][LOGN]; 
int dep[MAXN];

void dfs(int u, int p, int d, int w_from_p, int id_from_p) {
    dep[u] = d;
    up[u][0] = p;
    min_w[u][0] = w_from_p;  
    min_id[u][0] = id_from_p;
    
    for (int i = 1; i < LOGN; i++) {
        int ancestor = up[u][i - 1];
        up[u][i] = up[ancestor][i - 1];
        
        if (min_w[u][i - 1] < min_w[ancestor][i - 1]) {
            min_w[u][i] = min_w[u][i - 1];
            min_id[u][i] = min_id[u][i - 1];
        } else {
            min_w[u][i] = min_w[ancestor][i - 1];
            min_id[u][i] = min_id[ancestor][i - 1];
        }
    }

    for (auto& edge : adj[u]) {
        if (edge.v != p) {
            dfs(edge.v, u, d + 1, edge.w, edge.id);
        }
    }
}

int get_zero_edge_on_path(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    
    int potential_id = -1;
    
    for (int i = LOGN - 1; i >= 0; i--) {
        if (dep[u] - (1 << i) >= dep[v]) {
            if (min_w[u][i] == 0) potential_id = min_id[u][i];
            u = up[u][i];
        }
    }
    
    if (u == v) return potential_id;
    
    for (int i = LOGN - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            if (min_w[u][i] == 0) potential_id = min_id[u][i];
            if (min_w[v][i] == 0) potential_id = min_id[v][i];
            u = up[u][i];
            v = up[v][i];
        }
    }
    
    if (min_w[u][0] == 0) potential_id = min_id[u][0];
    if (min_w[v][0] == 0) potential_id = min_id[v][0];
    
    return potential_id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> all_edges;
    vector<Edge> original_edges;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        all_edges.push_back({u, v, w % 2, i}); 
    }

    original_edges = all_edges;

    sort(all_edges.begin(), all_edges.end()); 
    DSU dsu(n);
    vector<Edge> tree_edges;
    vector<bool> is_in_tree(m + 1, false);
    
    int ones_cnt = 0;
    for (auto& e : all_edges) {
        if (dsu.merge(e.u, e.v)) {
            is_in_tree[e.id] = true;
            tree_edges.push_back(e);
            adj[e.u].push_back({e.v, e.w, e.id});
            adj[e.v].push_back({e.u, e.w, e.id});
            if (e.w == 1) ones_cnt++;
        }
    }

    if (tree_edges.size() != n - 1) {
        cout << "NO" << endl; 
        return 0;
    }

    if (ones_cnt % 2 == 0) {
        cout << "YES" << endl; 
        for (auto& e : tree_edges) cout << e.id << " ";
        cout << endl;
        return 0;
    }

    dfs(1, 1, 0, INF, -1);

    int remove_id = -1, add_id = -1;

    for (auto& e : original_edges) {
        if (is_in_tree[e.id]) continue;
        if (e.w == 0) continue; 

        int zero_edge_id = get_zero_edge_on_path(e.u, e.v);
        
        if (zero_edge_id != -1) {
            remove_id = zero_edge_id;
            add_id = e.id;
            break;
        }
    }

    if (remove_id != -1) {
        cout << "YES" << endl;
        is_in_tree[remove_id] = false;
        is_in_tree[add_id] = true;
        for (int i = 1; i <= m; i++) {
            if (is_in_tree[i]) cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
