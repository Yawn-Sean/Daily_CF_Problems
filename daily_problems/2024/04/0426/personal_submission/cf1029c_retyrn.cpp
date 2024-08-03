int n;

void solve() {
    cin >> n;
    vector<pii> a(n);
    cin >> a;
    vector<pii> r(n + 1, mpr(0, inf));
    // 前后缀分解
    for (int i = 1; i <= n; i ++) {
        r[i] = r[i - 1];
        r[i].fi = max(r[i].fi, a[n - i].fi);
        r[i].se = min(r[i].se, a[n - i].se);
    }
    
    pii cur = {0, inf};
    int res = 0;
    for (int i = 0; i < n; i ++) {
        int L = max(cur.fi, r[n - i - 1].fi);
        int R = min(cur.se, r[n - i - 1].se);
        res = max(res, R - L);
        cur.fi = max(cur.fi, a[i].fi);
        cur.se = min(cur.se, a[i].se);
    }
    cout << res << endl;
}