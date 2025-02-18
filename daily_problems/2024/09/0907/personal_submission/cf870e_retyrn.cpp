int n;
void solve() {
    cin >> n;
    vector<pii> a(n);
    cin >> a;
    map<int, int> mpx, mpy;
    for (int i = 0; i < n; i ++) {
        mpx[a[i].fi] = 0;
        mpy[a[i].se] = 0;
    }
    
    int cur = 0;
    for (auto& [k, v] : mpx) {
        v = cur ++;
    }
    for (auto& [k, v] : mpy) {
        v = cur ++;
    }
    int m = cur;
    DSU dsu(m);
    
    for (auto [x, y] : a) {
        x = mpx[x];
        y = mpy[y];
        dsu.merge(x, y);
    }
    
    ll res = 1;
    for (int i = 0; i < m; i ++) {
        if (dsu.leader(i) != i) continue;
        int k = dsu.size(i), e = dsu.edge(i);
        res = (e == k - 1 ? powmod(2, k) - 1 : powmod(2, k)) * res % mod;
    }
    cout << res << endl;
}