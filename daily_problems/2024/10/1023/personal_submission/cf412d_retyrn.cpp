int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
    }
    
    vector<int> st(n, false);
    
    auto dfs = [&](auto&& dfs, int u) {
        if (st[u]) return;
        st[u] = true;
        for (auto x : g[u]) {
            dfs(dfs, x);
        }
        cout << u + 1 << ' ';
    };
    
    for (int i = 0; i < n; i ++) {
        dfs(dfs, i);
    }
}