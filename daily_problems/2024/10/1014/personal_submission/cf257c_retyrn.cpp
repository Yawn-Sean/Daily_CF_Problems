int n;

void solve() {
    cin >> n;
    vector<pii> a(n);
    cin >> a;
    vector<double> b(n);
    for (int i = 0; i < n; i ++) {
        b[i] = atan2(a[i].se, a[i].fi) * 180 / acos(-1);
    }
    sort(all(b));
    
    double res = b[0] + 360 - b[n-1];
    
    for (int i = 1; i < n; i ++) {
        chmax(res, b[i] - b[i - 1]);
    }
    cout << 360 - res << endl;
}