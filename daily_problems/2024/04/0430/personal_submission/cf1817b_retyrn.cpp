int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    while (m --) {
        int a, b;
        cin >> a >> b;
        g[a].pbk(b);
        g[b].pbk(a);
    }
    
    // 枚举作为u的点
    for (int t = 1; t <= n; t ++) {
        if (sz(g[t]) < 4) continue;
        // dfs找环 不使用t->v的边 从t出发找v
        for (auto v : g[t]) {
            vector<bool> st(n + 1, false);
            vector<int> path;
            vector<int> cur;
            function<void(int)> dfs = [&](int u) {
                st[u] = true;
                cur.push_back(u);
                if (u == v) {
                    path = cur;
                    return;
                }
                for (auto x : g[u]) {
                    if (st[x]) continue;
                    if (u == t && x == v) continue;
                    dfs(x);
                    if (!em(path)) return;
                }
                cur.pop_back();
            };
            dfs(t);
            if (em(path)) continue;
            vector<PII> res;
            for (int i = 1; i < sz(path); i ++) {
                res.pbk({path[i - 1], path[i]});
            }
            res.pbk({t, v});
            int cnt = 2;
            fill(all(st), false);
            for (auto x : path) st[x] = true;
            for (auto x : g[t]) {
                if (st[x]) continue;
                res.pbk({t, x});
                if (-- cnt == 0) break;
            }
            if (cnt) continue;
            cout << "YES" << endl;
            cout << sz(res) << endl;
            for (auto [x, y] : res) {
                cout << x << ' ' << y << endl;
            }
            return;
        }
    }
    cout << "NO" << endl;
}