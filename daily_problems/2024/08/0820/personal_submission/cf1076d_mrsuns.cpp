void Solve() {
    int n, m, k;cin >> n >> m >> k;
    vector<vector<array<int, 3>>>g(n + 1);
    for (int i = 1;i <= m;i++) {
        int u, v, w;cin >> u >> v >> w;
        g[u].push_back({ v,w,i });
        g[v].push_back({ u,w,i });
    }

    if (k == 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> vis(n + 1), dis(n + 1, inf), dp(n + 1);
    dis[1] = 0;dp[1] = -1;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
    q.push({ 0,1 });
    vector<int> res;
    while (q.size()) {
        auto [disu, u] = q.top();q.pop();
        if (vis[u]) continue;
        if (dp[u] != -1) {
            res.push_back(dp[u]);
            if (res.size() == k) break;
        }
        vis[u] = 1;
        for (auto [v, w, id] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dp[v] = id;
                dis[v] = dis[u] + w;
                q.push({ dis[v],v });
            }
        }
    }
    cout << res.size() << endl;
    for (auto i : res) cout << i << ' ';cout << endl;
}
