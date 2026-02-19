void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        g[a].push_back({b, w});
    }

    vector<i64> dis(n, inf);
    dis[0] = 0;
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
    pq.push({0, 0});
    vector<int> topo_order;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u]) {
            continue;
        }
        topo_order.push_back(u);
        for (auto &[v, w]: g[u]) {
            if (d + w < dis[v]) {
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }

    vector<int> res(n, 1e9);
    res[0] = 0;
    for (auto u: topo_order) {
        for (auto [v, w]: g[u]) {
            if (dis[v] == dis[u] + w) {
                chmin(res[v], max(res[u], w));
            }
        }
    }
    cout << dis[n - 1] << ' ' << res[n - 1];
}
