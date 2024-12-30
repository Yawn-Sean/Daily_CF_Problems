void Solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> isr(n + 1, 1);
    for (int i = 1;i <= m;i++) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        isr[v] = 0;
    }
    vector<int> use(n + 1);
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i], use[a[i]] = 1;
    vector<int> ord, res(n + 1);
    auto dfs = [&](auto&& dfs, int u)->void {
        if (use[u]) {
            ord.push_back(u);
            res[u] = u;
        }
        for (auto v : g[u]) {
            res[v] = res[u];
            dfs(dfs, v);
        }
        };
    for (int i = 1;i <= n;i++) {
        if (isr[i]) dfs(dfs, i);
    }
    if (res == a) {
        reverse(ord.begin(), ord.end());
        cout << ord.size() << endl;
        for (auto i : ord) cout << i << endl;
    }
    else cout << "-1\n";
}
