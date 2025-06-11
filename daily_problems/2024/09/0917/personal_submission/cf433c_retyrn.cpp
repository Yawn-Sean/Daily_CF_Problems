int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(m);
    cin >> a;
    ll sum = 0;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < m; i ++) {
        sum += abs(a[i] - a[i - 1]);
        if (a[i] == a[i - 1]) continue;
        g[a[i]].push_back(a[i - 1]);
        g[a[i - 1]].push_back(a[i]);
    }
    ll res = sum;
    
    for (int i = 1; i <= n; i ++) {
        if (em(g[i])) continue;
        sort(all(g[i]));
        int len = sz(g[i]);
        ll ans = sum;
        for (auto x : g[i]) {
            ans -= abs(x - i);
            ans += abs(x - g[i][len / 2]);
        }
        chmin(res, ans);
    }
    
    cout << res << endl;
}