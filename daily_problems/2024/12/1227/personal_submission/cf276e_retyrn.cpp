int n, q;

void solve() {
    cin >> n >> q;
    // 1个根上连着很多条链
    // 记录对所有的链的差分 前缀树状数组
    // 记录对每一条链的差分 前缀树状数组
    vector<vector<int>> g(n);
    int root = 0;
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for (int i = 0; i < n; i ++) {
        if (sz(g[i]) > sz(g[root])) root = i;
    }
    
    // 根据根节点反向找到每一条链
    vector<vector<int>> chain;
    vector<pii> pos(n, mpr(-1, -1));
    pos[root] = mpr(inf, inf);
    
    for (auto x : g[root]) {
        chain.push_back({x});
        pos[x].fi = sz(chain) - 1, pos[x].se = 1;
        queue<int> q;
        q.push(x);
        while (!em(q)) {
            auto ver = q.front();
            q.pop();
            for (auto y : g[ver]) {
                if (y == root or pos[y].fi >= 0) continue;
                q.push(y);
                chain.back().push_back(y);
                pos[y].fi = sz(chain) - 1, pos[y].se = pos[ver].se + 1;
            }
        }
    }
    
    int m = sz(chain);
    
    vector<Fenwick<ll>> fens(m);
    for (int i = 0; i < m; i ++) {
        int len = sz(chain[i]);
        fens[i].init(len + 2);
    }
    Fenwick<int> fen(n + 2);
    
    while (q --) {
        int op;
        cin >> op;
        if (op == 0) {
            int u, val, d;
            cin >> u >> val >> d;
            u --;
            if (u == root) {
                fen.add(0, val);
                fen.add(d + 1, -val);
                continue;
            }
            int x = pos[u].fi, y = pos[u].se;
            if (y - d > 0) {
                int up = min(y + d, sz(chain[x]));
                fens[x].add(y - d, val);
                fens[x].add(up + 1, -val);
            }
            else {
                // 考虑全局影响
                int down = min(d - y, sz(chain[x]));
                int up = min(y + d, sz(chain[x]));
                
                fen.add(0, val);
                fen.add(d - y + 1, -val);
                
                // fens[x].add(0, val);
                fens[x].add(up + 1, -val);
                // fens[x].add(0, -val);
                fens[x].add(down + 1, val);
            }
        }
        else {
            int u;
            cin >> u;
            u --;
            if (u == root) {
                cout << fen.rangeSum(0, 1) << endl;
                continue;
            }
            int x = pos[u].fi, y = pos[u].se;
            cout << fens[x].rangeSum(0, y + 1) + fen.rangeSum(0, y + 1) << endl;
        }
    }
}