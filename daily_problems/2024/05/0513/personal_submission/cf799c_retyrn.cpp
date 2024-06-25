int n, C, D;

void solve() {
    cin >> n >> C >> D;
    vector<vector<pii>> a(2);
    for (int i = 0; i < n; i ++) {
        int x, y;
        string op;
        cin >> x >> y >> op;
        if (op[0] == 'C') {
            a[0].emplace_back(y, x);
        }
        else {
            a[1].emplace_back(y, x);
        }
    }
    for (int i = 0; i < 2; i ++) {
        sort(all(a[i]));
    }
    int n0 = sz(a[0]), n1 = sz(a[1]);
    int res = 0;
    // 全都金币
    if (n0 >= 2 and a[0][0].fi + a[0][1].fi <= C) {
        BIT<int> bit(100000);
        for (int i = 0; i < n0 and a[0][i].fi < C; i ++) {
            auto t = bit.sum(C - a[0][i].fi);
            if (t > 0) res = max(res, a[0][i].se + t);
            bit.add(a[0][i].fi, a[0][i].se);
        }
    }
    
    // 全都钻石
    if (n1 >= 2 and a[1][0].fi + a[1][1].fi <= D) {
        BIT<int> bit(100000);
        for (int i = 0; i < n1 and a[1][i].fi < D; i ++) {
            auto t = bit.sum(D - a[1][i].fi);
            if (t > 0) res = max(res, a[1][i].se + t);
            bit.add(a[1][i].fi, a[1][i].se);
        }
    }
    
    // 一个钻石一个金币
    if (n0 >= 1 and n1 >= 1 and a[0][0].fi <= C and a[1][0].fi <= D) {
        int mx0 = 0, mx1 = 0;
        for (int i = 0; i < n0 and a[0][i].fi <= C; i ++) {
            mx0 = max(mx0, a[0][i].se);
        }
        for (int i = 0; i < n1 and a[1][i].fi <= D; i ++) {
            mx1 = max(mx1, a[1][i].se);
        }
        res = max(res, mx0 + mx1);
    }
    cout << res << endl;
}