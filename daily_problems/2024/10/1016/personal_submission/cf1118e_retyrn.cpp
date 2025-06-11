int n, k;

void solve() {
    cin >> n >> k;
    vector<pii> res(n);
    int idx = 0;
    
    auto add = [&](int a, int b) -> void {
        if (idx >= n) return;
        if (idx > 0 and (res[idx-1].fi == a or res[idx-1].se == b)) {
            res[idx].fi = b;
            res[idx].se = a;
        }
        else {
            res[idx].fi = a;
            res[idx].se = b;
        }
        idx ++;
    };
    
    for (int u = k; u > 1 and idx < n; u --) {
        for (int i = 1; i < u and idx < n; i ++) {
            add(i, u);
            add(u, i);
        }
    }
    
    if (idx == n) {
        cout << "YES" << endl;
        for (auto [x, y] : res) {
            cout << x << ' ' << y << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
}