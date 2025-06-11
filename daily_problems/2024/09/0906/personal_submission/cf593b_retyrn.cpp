int n;
int x1, x2;

void solve() {
    cin >> n;
    cin >> x1 >> x2;
    vector<pii> a(n);
    cin >> a;
    
    sort(all(a), [&](pii& x, pii& y) {
        return (ll)x.fi * x1 + x.se < (ll)y.fi * x1 + y.se;
    });
    
    ll mx = -inf2;
    for (int i = 1, j = 0; i < n; i ++) {
        auto cur = (ll)a[i].fi * x1 + a[i].se;
        while (j < i and (ll)a[j].fi * x1 + a[j].se < cur) {
            chmax(mx, (ll)a[j].fi * x2 + a[j].se);
            j ++;
        }
        if (mx > (ll)a[i].fi * x2 + a[i].se) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}