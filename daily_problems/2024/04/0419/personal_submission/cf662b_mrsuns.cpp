void Solve() {
    int n, m;cin >> n >> m;
    vector<array<int, 3>> edge;
    for (int i = 1;i <= m;i++) {
        int u, v;char c;cin >> u >> v >> c;
        int val = 0;
        if (c == 'B') val = 1;
        edge.push_back({ u,v,val });
    }
    vector<int> ans[2];array<int, 2> IF;
    for (int i = 0;i < 2;i++) {
        auto check = [&](vector<int>& ans) {
            for (int j = 1;j <= 2 * n;j++) p[j] = j, sz[j] = (j <= n);
            for (auto [u, v, col] : edge) {
                if (col == i) {
                    merge(u, v);
                    merge(u + n, v + n);
                }
                else {
                    merge(v, u + n);
                    merge(u, v + n);
                }
            }
            for (int i = 1;i <= n;i++) {
                if (find(i) == find(i + n)) return 0;
            }
            vector<int> vis(2 * n + 1);
            for (int j = 1;j <= n;j++) {
                int u = find(j), v = find(j + n);
                if (!vis[u] && !vis[v]) {
                    if (sz[u] < sz[v]) ans.push_back(j), vis[u] = 1;
                    else vis[v] = 1;
                }
                else {
                    if (vis[u]) ans.push_back(j);
                }
            }
            return 1;
            };
        IF[i] = check(ans[i]);
    }

    auto outp = [&](vector<int>& ans) {
        cout << ans.size() << endl;
        for (auto i : ans) cout << i << " ";cout << endl;
        };
    if (!IF[0] && !IF[1]) cout << -1 << endl;
    else if (IF[0] && IF[1]) {
        if (ans[0].size() < ans[1].size()) outp(ans[0]);
        else outp(ans[1]);
    }
    else if (IF[0]) outp(ans[0]);
    else outp(ans[1]);
}
