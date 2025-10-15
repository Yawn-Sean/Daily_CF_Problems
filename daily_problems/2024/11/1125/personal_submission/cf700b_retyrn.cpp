int n, k;

void solve() {
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<int> need(n, 0);
    
    for (int i = 0; i < (k << 1); i ++) {
        int x;
        cin >> x;
        x --;
        need[x] = 1;
    }
    
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    ll res = 0;
    
    auto dfs = [&](auto&& self, int u, int fa) -> int {
        int s = need[u];
        for (auto x : g[u]) {
            if (x == fa) continue;
            auto t = self(self, x, u);
            res += min(t, k * 2 - t);
            s += t;
        }
        return s;
    };
    
    dfs(dfs, 0, -1);
    
    cout << res << endl;
    
}