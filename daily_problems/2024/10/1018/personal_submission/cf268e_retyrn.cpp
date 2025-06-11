int n;

void solve() {
    cin >> n;
    vector<pii> a(n);
    cin >> a;
    
    sort(all(a), [](pii& x, pii& y) {
        return (ll)x.fi * x.se * (100 - y.se) > (ll)y.fi * y.se * (100 - x.se);
    });
    
    double res = 0, like = 0;
    
    for (auto [x, pro] : a) {
        double p = pro / 100.0;
        res += x;
        res += like * (1.0 - p);
        like += p * x;
    }
    cout << res << endl;
}