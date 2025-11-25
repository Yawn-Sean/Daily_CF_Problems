#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct UnionFind {
    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            return true;
        }
        return false;
    }
};

const int LOG = 20;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> us(m), vs(m), ws(m);
    vector<int> p(m);

    for (int i = 0; i < m; ++i) {
        cin >> us[i] >> vs[i] >> ws[i];
        us[i]--;
        vs[i]--;
        p[i] = i;
    }

    sort(p.begin(), p.end(), [&](int a, int b) {
        return ws[a] < ws[b];
    });

    UnionFind uf(n);
    vector<vector<pair<int, int>>> adj(n);
    vector<bool> chosen(m, false);

    for (int i : p) {
        if (uf.merge(us[i], vs[i])) {
            chosen[i] = true;
            adj[us[i]].push_back({vs[i], ws[i]});
            adj[vs[i]].push_back({us[i], ws[i]});
        }
    }

    vector<int> depth(n, 0);
    vector<long long> to_root(n, 0);
    vector<vector<int>> up(LOG, vector<int>(n, -1));
    
    vector<int> q;
    q.reserve(n);
    q.push_back(0);
    
    int head = 0;
    while(head < q.size()){
        int u = q[head++];
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (v != up[0][u]) {
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                to_root[v] = to_root[u] + w;
                q.push_back(v);
            }
        }
    }

    for (int i = 0; i < LOG - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (up[i][j] != -1) {
                up[i + 1][j] = up[i][up[i][j]];
            } else {
                up[i + 1][j] = -1;
            }
        }
    }

    auto get_lca = [&](int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        int d = depth[v] - depth[u];
        for (int i = 0; i < LOG; ++i) {
            if ((d >> i) & 1) {
                v = up[i][v];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        }
        return up[0][u];
    };

    for (int i = 0; i < m; ++i) {
        if (!chosen[i]) {
            int u = us[i];
            int v = vs[i];
            int l = get_lca(u, v);
            long long dist = to_root[u] + to_root[v] - 2 * to_root[l];
            if (dist > ws[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    return 0;
}
