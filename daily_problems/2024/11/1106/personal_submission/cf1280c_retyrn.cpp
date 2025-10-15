int n;

void solve() {
    cin >> n;
    n <<= 1;
    vector<vector<pii>> g(n);
    for (int i = 0; i < n - 1; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        x --, y --;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    
    vector<int> size(n);
    ll mx = 0, mn = 0;
    
    auto dfs = [&](auto&& dfs, int u, int fa) -> void {
        size[u] = 1;
        for (auto [x, w] : g[u]) {
            if (x == fa) continue;
            dfs(dfs, x, u);
            if (size[x] & 1) {
                mn += w;
            }
            mx += (ll)w * min(n - size[x], size[x]);
            
            size[u] += size[x];
        }
    };
    
    dfs(dfs, 0, -1);
    
    cout << mn << ' ' << mx << endl;
}