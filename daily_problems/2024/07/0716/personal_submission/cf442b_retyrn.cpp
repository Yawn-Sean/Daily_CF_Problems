int n;

void solve() {
    cin >> n;
    vector<double> a(n);
    cin >> a;
    
    sort(all(a), greater<>());
    
    double p0 = 1.0, p1 = 0.0;
    double res = 0.0, cur = 0.0;
    
    for (auto& x: a) {
        cur += (p0 - p1) * x;
        chmax(res, cur);
        p1 = p1 * (1 - x) + p0 * x;
        p0 = p0 * (1 - x);
    }
    
    cout << res << endl;
}
