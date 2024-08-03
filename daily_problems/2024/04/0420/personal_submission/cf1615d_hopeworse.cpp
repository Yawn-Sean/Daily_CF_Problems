class solution {
private:
    vector<vector<pair<int, int>>> adj;
    vector<tuple<int, int, int>> edges;
    DSU dsu;
    vector<int> dis;

    void add_edge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    void merge(int u, int v, int n, int w) {
        int cnt = __builtin_popcountll(w);
        if (cnt % 2 == 0) {
            dsu.merge(u, v);
            dsu.merge(u + n, v + n);
        } else {
            dsu.merge(u, v + n);
            dsu.merge(u + n, v);
        }
    }


    void dfs(int u, int v) {
        for (auto [to, id]: adj[u]) {
            if (to == v) continue;

            int &w = get<2>(edges[id]);
            debug(id, dis[u], dis[to]);
            debug(edges[id]);
            if (w == -1) {
                if (dis[u] != dis[to]) {
                    w = 1;
                } else {
                    w = 0;
                }
            }
            dfs(to, u);
        }
    }

public:
    void run() {
        int n, m;
        cin >> n >> m;
        dsu = DSU(2 * n + 10);
        adj.resize(n + 10);
        dis.resize(n + 10);
        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            add_edge(u, v, i);
            if (w != -1) {
                merge(u, v, n, w);
            }
            edges.emplace_back(u, v, w);
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            merge(u, v, n, w);
        }
        for (int i = 1; i <= n; i++) {
            if (dsu.find(i) == dsu.find(i + n)) {
                cout << "NO" << endl;
                return;
            }
        }
        for (int i = 1; i <= n; i++) {
            dis[i] = dsu.find(i) <= n;
        }
        if (dis[1]) {
            for (int i = 1; i <= n; i++) {
                dis[i] ^= 1;
            }
        }
        dfs(1, 0);
        cout << "YES" << endl;
        for (auto [u, v, w]: edges) {
            cout << u << " " << v << " " << w << endl;
        }
        return;
    }
};
