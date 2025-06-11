int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    int mx = a[n - 1], mn = a[0];
    int d = mx - mn;
    vector<double> f(d + 1), fs(d * 2 + 1);
    
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            f[a[j] - a[i]] += 1.0 / n / (n - 1);
        }
    }
    
    for (int i = 0; i <= d * 2; i ++) {
        for (int j = max(0, i - d); j <= d and j <= i; j ++) {
            fs[i] += f[j] * f[i - j];
        }
    }
    
    for (int i = 1; i <= (d << 1); i ++) {
        fs[i] += fs[i - 1];
    }
    
    double res = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            double cur = 1.0 / n / (n - 1);
            int diff = a[j] - a[i];
            if (diff > 0) {
                cur *= fs[diff - 1];
            }
            res += cur;
        }
    }
    cout << res * 8 << endl;
    
}