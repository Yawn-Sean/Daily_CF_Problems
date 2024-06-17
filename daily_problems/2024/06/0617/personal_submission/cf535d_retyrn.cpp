void solve() {
    cin >> n >> m;
    cin >> s;
    int len = sz(s);
    vector<int> z = z_function(s);
    vector<int> p(m);
    for (int i = 0; i < m; i ++) {
        cin >> p[i];
        p[i] -= 1;
    }
    
    if (em(p)) {
        ll res = powmod(26, n);
        cout << res << endl;
        return;
    }
    
    ll res = powmod(26, p[0] + (n - 1) - (p.back() + len - 1));
    for (int i = 1; i < m; i ++) {
        if (p[i - 1] + len - 1 >= p[i]) {
            // 连起来的
            if (z[p[i] - p[i - 1]] != len - (p[i] - p[i - 1])) {
                cout << 0 << endl;
                return;
            }
        }
        else {
            int t = p[i] - (p[i - 1] + len);
            res = res * powmod(26, t) % mod;
        }
    }
    cout << res << endl;
}