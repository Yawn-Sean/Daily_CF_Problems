void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto cal = [&](vector<int> a) -> MInt<P> {
        vector<int> ids(n), vis(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return a[i] < a[j];
        });
        DSU dsu(n);
        Z res = 0;
        for (int u: ids) {
            for (int v: g[u]) {
                if (!vis[v]) continue;
                res += Z(1) * a[u] * dsu.size(u) * dsu.size(v);
                dsu.merge(u, v);
            }
            vis[u] = 1;
        }
        return res;
    };
    Z res = cal(a);
    for (int& x: a) {
        x = -x;
    }
    res += cal(a);
    res /= Z(1) * n * (n - 1) / 2;
    cout << res << '\n';
}
