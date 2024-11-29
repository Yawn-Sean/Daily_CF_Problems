int n;

void solve() {
    cin >> n;
    vector<pii> a(n);
    ll res = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
        chmax(res, (ll)a[i].fi * a[i].se);
    }
    
    sort(all(a), greater<pii>());
    int mx1 = 0, mx2 = 0;
    
    for (int i = 0; i < n; i ++) {
        if (a[i].se > mx1) mx2 = mx1, mx1 = a[i].se;
        else if (a[i].se > mx2) mx2 = a[i].se;
        if (mx2 > 0) {
            chmax(res, 2ll * mx2 * a[i].fi);
        }
    }
    if (res & 1) {
        cout << res / 2 << ".5" << endl;
        return;
    }
    cout << res / 2 << ".0" << endl;
}