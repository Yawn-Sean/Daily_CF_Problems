int n, l, t;

void solve() {
    cin >> n >> l >> t;
    vector<int> a(n);
    cin >> a;
    
    for (int i = 0; i < n; i ++) {
        a.push_back(a[i] + l);
    }
    
    int d = (t * 2) % l;
    double res = (double)n * (n - 1) * (t * 2 / l);
    
    for (int i = 0; i < n; i ++) {
        res += upper_bound(all(a), a[i] + d) - a.begin() - 1 - i;
    }
    cout << res / 4 << endl;
}