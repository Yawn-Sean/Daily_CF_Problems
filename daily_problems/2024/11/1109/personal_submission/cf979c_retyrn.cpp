int n;
int x, y;

void solve() {
    cin >> n >> x >> y;
    x --, y --;
    vector<vector<int>> g(n);
    
    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        a --, b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> st(n, 0);
    
    auto dfs = [&](auto&& dfs, int u, int fa, int ban, int s) -> void {
        if (u == ban) return;
        st[u] |= s;
        for (auto x : g[u]) {
            if (x == fa) continue;
            dfs(dfs, x, u, ban, s);
        }
    };
    
    dfs(dfs, x, -1, y, 1);
    dfs(dfs, y, -1, x, 2);
    
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i ++) {
        c1 += (st[i] == 1);
        c2 += (st[i] == 2);
    }
    
    ll res = (ll)n * (n - 1) - (ll)c1 * c2;
    
    cout << res << endl;
}