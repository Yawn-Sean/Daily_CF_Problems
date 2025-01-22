int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    
    vector<double> p;
    
    auto check = [&](double d) -> bool {
        p.clear();
        p.push_back(min(a[0] + d, (double)a.back()));
        for (int i = 0; i < n; i ++) {
            if (fabs(a[i] - p.back()) < d + eps) continue;
            p.push_back(min(a[i] + d, (double)a.back()));
            if (sz(p) > 3) return false;
        }
        return true;
    };
    
    double l = 0.0, r = a.back() / 2.0;
    while (r - l > eps) {
        auto mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    check(r);
    
    while (sz(p) < 3) p.push_back(a.back());
    
    cout << p[0] << ' ' << p[1] << ' ' << p[2] << endl;
    
}