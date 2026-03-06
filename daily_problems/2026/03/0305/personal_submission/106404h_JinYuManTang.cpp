void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({a[i], i});
    }
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > a[u]) {
            continue;
        }
        for (auto [v, w]: g[u]) {
            if (a[u] + w < a[v]) {
                a[v] = a[u] + w;
                pq.push({a[v], v});
            }
        }
    }
    vector<i64> dis(n, inf);
    dis[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u]) {
            continue;
        }
        for (auto [v, w]: g[u]) {
            if (dis[u] + w < dis[v] && dis[u] + w <= a[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    cout << (dis[n - 1] < inf ? "YES\n" : "NO\n");
}
