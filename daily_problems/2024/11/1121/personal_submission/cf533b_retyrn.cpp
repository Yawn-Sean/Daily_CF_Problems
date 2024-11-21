int n;

void solve() {
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> w(n);
    for (int i = 0; i < n; i ++) {
        int fa;
        cin >> fa >> w[i];
        fa --;
        if (fa >= 0) g[fa].push_back(i);
    } 
    
    vector<vector<ll>> f(n, vector<ll>(2, 0));
    
    auto dfs = [&](auto&& self, int u) -> void {
        f[u][0] = 0, f[u][1] = -inf2;
        for (auto x : g[u]) {
            self(self, x);
            ll v0 = f[u][0], v1 = f[u][1];
            f[u][0] = max(f[x][0] + v0, f[x][1] + v1);
            f[u][1] = max(f[x][1] + v0, f[x][0] + v1);
        }
        f[u][1] = max(f[u][1], f[u][0] + w[u]);
    };
    
    dfs(dfs, 0);
    
    cout << max(f[0][0], f[0][1]) << endl;
    
}