int n, tx, ty;
const double pi = acos(-1.0);

ll cross(const pii& x, const pii& y) {
    auto t = (ll)x.fi * y.se - (ll)y.fi * x.se;
    return abs(t);
}

bool check(const pii& v1, const pii& v2) {
    ll t = (ll)v1.fi * v2.fi + (ll)v1.se * v2.se;
    return t > 0;
}

void solve() {
    cin >> n >> tx >> ty;
    vector<pii> a(n);
    double l = 2e18, r = -2e18;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i].fi -= tx;
        a[i].se -= ty;
        double t = sqrt((ll)a[i].fi * a[i].fi + (ll)a[i].se * a[i].se);
        chmax(r, t);
        chmin(l, t);
    }
    a.push_back(a[0]);
    
    for (int i = 0; i < n; i ++) {
        pii v1 = mpr(-a[i].fi, -a[i].se);
        pii v2 = mpr(a[i+1].fi - a[i].fi, a[i+1].se - a[i].se);
        pii v3 = mpr(a[i].fi - a[i+1].fi, a[i].se - a[i+1].se);
        pii v4 = mpr(-a[i+1].fi, -a[i+1].se);
        
        if (check(v1, v2) and check(v3, v4)) {
            double len = sqrt((ll)(a[i].fi - a[i+1].fi) * (a[i].fi - a[i+1].fi) + (ll)(a[i].se - a[i+1].se) * (a[i].se - a[i+1].se));
            double cs = cross(a[i], a[i+1]);
            double d = cs / len;
            chmin(l, d);
        }
    }
    cout << (r * r - l * l) * pi << endl;
}