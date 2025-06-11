int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    vector<vector<int>> g(n);
    
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    vector<ll> f1(n, -inf2), f2(n, -inf2), s(n, 0);
    ll res = -inf2;
    
    auto dfs = [&](auto& dfs, int u, int fa) -> void {
        ll sum = a[u];
        ll mx1 = -inf2, mx2 = -inf2;
        for (auto x : g[u]) {
            if (x == fa) continue;
            dfs(dfs, x, u);
            sum += s[x];
            if (f1[x] > mx1) mx2 = mx1, mx1 = f1[x];
            else if (f1[x] > mx2) mx2 = f1[x];
        }
        
        if (mx2 > -inf2) chmax(res, mx1 + mx2);
        s[u] = sum;
        if (sum > mx1) mx2 = mx1, mx1 = sum;
        else if (sum > mx2) mx2 = sum;
        f1[u] = mx1, f2[u] = mx2;
    };
    
    dfs(dfs, 0, -1);
    
    if (res == -inf2) {
        cout << "Impossible" << endl;
        return;
    }
    cout << res << endl;
}