int n, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    vector<pii> p;
    for (int i = 2; i <= k / i; i ++) {
        if (k % i) continue;
        p.push_back({i, 0});
        while (k % i == 0) {
            k /= i;
            p.back().se += 1;
        }
    }
    if (k > 1) p.push_back({k, 1});
    
    int m = sz(p);
    // 不同的因数至多不会超过10个
    
    vector<vector<int>> f(m, vector<int>(n + 1));
    for (int i = 0; i < n; i ++) {
        int x = a[i];
        for (int j = 0; j < m; j ++) {
            while (x % p[j].fi == 0) {
                x /= p[j].fi;
                f[j][i + 1] += 1;
            }
        }
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 1; j <= n; j ++) {
            f[i][j] += f[i][j - 1];
        }
    }
    
    auto check = [&](int l, int r) -> bool {
        if (l > r) return false;
        for (int i = 0; i < m; i ++) {
            int val = f[i][r + 1] - f[i][l];
            if (val < p[i].se) return false;
        }
        return true;
    };
    
    ll res = 0;
    for (int i = 0, j = 0; i < n; i ++) {
        while (j < n and !check(i, j)) j ++;
        res += (n - j);
    }
    cout << res << endl;
}