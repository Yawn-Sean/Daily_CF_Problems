int n;
using pil = pair<int, ll>;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<pil> l(n), r(n);
    r[n - 1] = mpr(a.back(), 0ll);
    for (int i = n - 2; i >= 0; i --) {
        int t = max(a[i], r[i + 1].fi + 1);
        ll cost = r[i + 1].se + t - a[i];
        r[i] = mpr(t, cost);
    }
    l[0] = mpr(a[0], 0ll);
    for (int i = 1; i < n; i ++) {
        int t = max(a[i], l[i - 1].fi + 1);
        ll cost = l[i - 1].se + t - a[i];
        l[i] = mpr(t, cost);
    }
    
    ll res = inf2;
    for (int i = 0; i < n; i ++) {
        ll cost = l[i].se + r[i].se - min(l[i].fi, r[i].fi) + a[i];
        chmin(res, cost);
    }
    cout << res << endl;
}