void Solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> deg(n + 1);
    vector<array<int, 2>> edge(1);
    for (int i = 1;i <= m;i++) {
        int u, v;cin >> u >> v;
        edge.push_back({ u,v });
    }
    auto check = [&](int x) {
        for (int i = 1;i <= n;i++) g[i].clear();
        for (int i = 1;i <= n;i++) deg[i] = 0;
        for (int i = 1;i <= x;i++) {
            auto [u, v] = edge[i];
            g[u].push_back(v);
            deg[v] += 1;
        }
        queue<int> q;
        for (int i = 1;i <= n;i++) {
            if (deg[i] == 0) q.push(i);
        }
        while (q.size()) {
            if (q.size() > 1) return 0;
            auto u = q.front();q.pop();
            for (auto v : g[u]) {
                if (--deg[v] == 0) q.push(v);
            }
        }
        for (int i = 1;i <= n;i++) {
            if (deg[i] > 0) return 0;
        }
        return 1;
        };
    int l = 1, r = m;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    int ans = r + 1;
    if (ans > m) cout << -1 << endl;
    else cout << ans << endl;

}
