int n, m;

void solve() {
    cin >> n >> m;
    vector<pii> e(m);
    cin >> e;
    
    vector<vector<pii>> res(n + 1);
    for (int i = 1; i <= n; i ++) {
        res[i].emplace_back(i, i);
    }
    for (int i = 0; i < m; i ++) {
        int x = e[i].fi, y = e[i].se;
        res[x].emplace_back(x, n + i + 1);
        res[y].emplace_back(y, n + i + 1);
    }
    
    for (int i = 1; i <= n; i ++) {
        cout << sz(res[i]) << endl;
        for (auto [x, y] : res[i]) {
            cout << x << ' ' << y << endl;
        }
    }
}