void solve() {
    cin >> n;
    pre.resize(n + 10, vector<int>(N, 0));
    d.resize(n + 10, 0);
    g.resize(n + 1); // 建图
    vector<pii> es;
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        es.emplace_back(x, y);
    }
    getpre(1, 0);
    
    vector<pii> dfn(n + 1);
    int idx = 1;
    auto dfs = [&](auto&& self, int u, int fa) -> void {
        dfn[u].fi = idx ++;
        for (auto x: g[u]) {
            if (x == fa) continue;
            self(self, x, u);
        }
        dfn[u].se = idx ++;
    };
    
    dfs(dfs, 1, 0);
    
    auto cal = [&](int x, int y) -> int {
        auto t = lca(x, y);
        return d[x] + d[y] - d[t] * 2;
    };
    
    int m = idx;
    
    Fenwick<int> fen(m + 5);
    
    cin >> q;
    while (q --) {
        int op;
        cin >> op;
        if (op == 1 or op == 2) {
            int id;
            cin >> id;
            id --;
            int x = es[id].fi, y = es[id].se;
            // 让x是y的父节点
            if (d[x] > d[y]) swap(x, y);
            // y为根的子树全体都要+1
            fen.add(dfn[y].fi, (op == 1 ? -1 : 1));
            fen.add(dfn[y].se + 1, (op == 1 ? 1 : -1));
        }
        else {
            int x, y;
            cin >> x >> y;
            
            int root = lca(x, y);
            int cnt = fen.sum(dfn[x].fi + 1) + fen.sum(dfn[y].fi + 1) - fen.sum(dfn[root].fi + 1) * 2;
            if (cnt) {
                cout << -1 << endl;
            }
            else {
                cout << cal(x, y) << endl;
            }
        }
    }
    
    
}