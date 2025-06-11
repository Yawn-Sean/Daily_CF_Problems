#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        考虑多源BFS 从每个志愿者所在的点出发bfs
        那么 q 步 内能够到达的点有什么特征?

        u->x
        v->x
        x如果都是距离uv更近 max(dis[u], dis[v])
        否则是u->x  x<-v这样更近 需要走的距离=dis[u]+dis[v]+1

    */
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> vis(n + 1);
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        vis[x] = 1;
    }

    vector<vector<int>> path(n + 1);
    vector<pair<int,int>> edges(m);
    for (auto& [u, v]: edges) {
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    vector<int> dis(n + 1, n), froms(n + 1, -1);
    int s, t;
    cin >> s >> t;
    vis[t] = 1;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            dis[i] = 0;
            froms[i] = i;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto&v: path[u]) {
            if (dis[v] == n) {
                dis[v] = dis[u] + 1;
                froms[v] = froms[u]; //
                q.push(v);
            }
        }
    }

    vector<vector<int>> tmp(n);
    for (int i = 0; i < m; i++) {
        auto& [u, v] = edges[i];
        int w = (froms[u] == froms[v] ? max(dis[u], dis[v]) : dis[u] + dis[v] + 1);
        if (w < n) {
            tmp[w].emplace_back(i);
        }
    }

    DSU d(n + 1);
    // 根据距离从小到大合并边
    // 直到s-t在一个分量内部
    for (int i = 0; i < n; i++) {
        for (auto&j: tmp[i]) {
            auto& [u, v] = edges[j];
            d.merge(u, v);
            if (d.find(s) == d.find(t)) {
                cout << i;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
