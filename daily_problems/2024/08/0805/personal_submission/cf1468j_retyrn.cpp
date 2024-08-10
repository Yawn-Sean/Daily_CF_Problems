int n, m, k;
using ai3 = array<int, 3>;

void solve() {
    cin >> n >> m >> k;
    vector<ai3> E(m);
    for (int i = 0; i < m; i ++) {
        cin >> E[i][1] >> E[i][2] >> E[i][0];
        E[i][1] -= 1;
        E[i][2] -= 1;
    }
    sort(all(E));
    DSU dsu(n);
    ll res = 0;
    int mx = 0;
    
    for (auto [w, x, y] : E) {
        if (dsu.same(x, y)) continue;
        res += max(0, w - k);
        mx = max(mx, w);
        dsu.merge(x, y);
    }
    if (mx >= k) {
        cout << res << endl;
        return;
    }
    
    res = inf2;
    for (auto& [w, x, y] : E) {
        chmin(res, (ll)abs(k - w));
    }
    cout << res << endl;
}