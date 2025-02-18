int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    ll res = 0;
    vector<ll> f(n, 0);
    
    for (int i = 0; i < n; i ++) {
        f[i] = 1;
        for (auto x : g[i]) {
            if (x < i) chmax(f[i], f[x] + 1);
        }
        chmax(res, (ll)f[i] * sz(g[i]));
    }
    cout << res << endl;
}