int n, m, D;

void solve() {
    cin >> n >> m >> D;
    vector<vector<int>> g(n);
    DSU dsu(n);
    
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        a --, b --;
        g[a].push_back(b);
        g[b].push_back(a);
        
        if (a and b) {
            dsu.merge(a, b);
        }
    }
    vector<pii> res;
    if (sz(g[0]) < D) {
        cout << "NO" << endl;
        return;
    }
    vector<int> wait;
    for (auto x : g[0]) {
        if (!dsu.same(x, 0)) {
            if (D <= 0) {
                cout << "NO" << endl;
                return;
            }
            res.push_back({0, x});
            dsu.merge(0, x);
            D --;
        }
        else {
            wait.push_back(x);
        }
    }
    
    for (int i = 1; i < n; i ++) {
        if (!dsu.same(0, i)) {
            cout << "NO" << endl;
            return;
        }
    }
    
    while (D > 0 and sz(wait)) {
        res.push_back({0, wait.back()});
        wait.pop_back();
        D --;
    }
    
    vector<bool> st(n, false);
    st[0] = true;
    queue<int> q;
    for (auto [x, y] : res) {
        q.push(y);
        st[y] = true;
    }
    
    while (!em(q)) {
        auto t = q.front();
        q.pop();
        for (auto x : g[t]) {
            if (st[x]) continue;
            st[x] = true;
            q.push(x);
            res.push_back({t, x});
        }
    }
    
    cout << "YES" << endl;
    for (auto [x, y] : res) {
        cout << x + 1 << ' ' << y + 1 << endl;
    }
}