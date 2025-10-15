void solve() {
    cin >> n >> k;
    vector<double> a(128);
    for (int i = 0; i <= k; i ++) {
        cin >> a[i];
    }
    
    vector<vector<double>> f(128, vector<double>(128, 0.0));
    
    for (int i = 0; i < 128; i ++) {
        for (int j = 0; j < 128; j ++) {
            int t = i ^ j;
            f[i][t] += a[j];
        }
    }
    
    vector<vector<double>> b(1, vector<double>(128, 0.0));
    b[0][0] = 1.0;
    
    auto ff = mat_pow(f, n);
    auto res = mat_mul(b, ff);
    
    double ans = 1.0 - res[0][0];
    
    cout << ans << endl;
}