void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> edge(m);
    vector<ll> weight(m);
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edge[i] = u ^ v;
        weight[i] = w;
        G[u].emplace_back(i);
        G[v].emplace_back(i);
    }
    vector<ll> dist(n, 1LL << 60);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (int eid : G[u]) {
            int to = edge[eid] ^ u;
            ll w = weight[eid];
            if (d + w < dist[to]) {
                dist[to] = d + w;
                pq.push({dist[to], to});
            }
        }
    }
    vector<int> ans;
    UF dsu(n);
    queue<int> q;
    q.push(0);
    vector<int> vis(n);
    vis[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int eid : G[u]) {
            int v = edge[eid] ^ u;
            int w = weight[eid];
            if (vis[v]) continue;
            if (dist[u] + w == dist[v] && !dsu.sameSet(u, v) && dsu.sameSet(u, 0)) {
                if (ans.size() < k) {
                    ans.emplace_back(eid);
                    q.push(v);
                    vis[v] = 1;
                    dsu.join(u, v);
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";
}
 
