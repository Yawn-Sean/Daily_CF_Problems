void Solve() {
    int n, m, q;cin >> n >> m >> q;
    vector<int> rs(n + m + 1), xs(n + m + 1), ys(n + m + 1);
    for (int i = 1;i <= n;i++) {
        rs[i] = 0;cin >> xs[i] >> ys[i];
    }
    for (int i = n + 1;i <= n + m;i++) {
        cin >> rs[i] >> xs[i] >> ys[i];
    }
    auto dis2 = [&](int i, int j) {
        return (xs[i] - xs[j]) * (xs[i] - xs[j]) + (ys[i] - ys[j]) * (ys[i] - ys[j]);
        };
    rs.push_back(1e10);xs.push_back(0);ys.push_back(0);
    vector<int> ids(n + m + 2);
    iota(ids.begin(), ids.end(), 0LL);
    sort(ids.begin() + 1, ids.end(), [&](auto u, auto v) {return rs[u] > rs[v];});
    vector<int> dep(n + m + 2);vector<vector<int>> g(n + m + 2);
    for (int i = 2;i <= n + m + 1;i++) {
        for (int j = i - 1;j >= 1;j--) {
            int u = ids[i], v = ids[j];
            if (dis2(u, v) < (rs[u] - rs[v]) * (rs[u] - rs[v])) {
                g[v].push_back(u);
                break;
            }
        }
    }
    LCA lca(n + m + 1);
    lca.init(g, n + m + 1);
    while (q--) {
        int u, v;cin >> u >> v;
        cout << (u == v ? 0 : lca.dis(u, v) - 2) << endl;
    }
}
