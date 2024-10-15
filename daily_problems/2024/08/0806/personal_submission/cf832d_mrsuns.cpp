void Solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 2;i <= n;i++) {
        int p;cin >> p;
        g[p].push_back(i);
    }
    vector<int> dep(n + 1);
    vector fa(n + 1, vector<int>(21));
    auto dfs = [&](auto&& dfs, int u)->void {
        for (auto v : g[u]) {
            dep[v] = dep[u] + 1;
            fa[v][0] = u;
            dfs(dfs, v);
        }
        };
    dfs(dfs, 1);

    for (int i = 1;i <= 20;i++) {
        for (int j = 1;j <= n;j++) {
            auto a = fa[j][i - 1];
            fa[j][i] = fa[a][i - 1];
        }
    }
    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y]) swap(x, y);
        for (int i = 20;i >= 0;i--) {
            if (fa[x][i] == 0) continue;
            if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
        }
        if (x == y) return x;
        for (int i = 20;i >= 0;i--) {
            if (fa[x][i] == 0 || fa[y][i] == 0) continue;
            if (fa[x][i] != fa[y][i]) {
                x = fa[x][i], y = fa[y][i];
            }
        }
        return fa[x][0];
        };

    auto dis = [&](int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
        };
    while (m--) {
        int a, b, c;cin >> a >> b >> c;
        int xy = dis(a, b);
        int xz = dis(a, c);
        int yz = dis(b, c);
        if (lca(a, b) == c || lca(a, c) == b || lca(b, c) == a) {
            vector<int> v;
            v.push_back(xy);
            v.push_back(xz);
            v.push_back(yz);
            sort(v.begin(), v.end());
            cout << v[1] + 1 << endl;
        }
        else {
            int x = (xy + xz - yz) / 2;
            int y = xy - x;
            int z = xz - x;
            cout << max({ x,y,z }) + 1 << endl;
        }
    }
}
