int n;

void solve() {
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    vector<ll> fact(n + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= n; i ++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    
    function<ll(int, int)> dfs = [&](int u, int fa) {
        ll res = fact[sz(g[u])];
        for (auto x : g[u]) {
            if (x == fa) continue;
            res = res * dfs(x, u) % mod;
        }
        return res;
    };
    ll res = dfs(0, -1) * n % mod;
    cout << res << endl;
}