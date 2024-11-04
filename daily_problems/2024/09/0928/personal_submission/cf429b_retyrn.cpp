int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    cin >> a;
    
    vector<vector<ll>> f00(n, vector<ll>(m));
    auto f01 = f00;
    auto f10 = f00;
    auto f11 = f00;
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            f00[i][j] = a[i][j];
            if (i - 1 >= 0) chmax(f00[i][j], f00[i - 1][j] + a[i][j]);
            if (j - 1 >= 0) chmax(f00[i][j], f00[i][j - 1] + a[i][j]);
        }
        for (int j = m - 1; j >= 0; j --) {
            f01[i][j] = a[i][j];
            if (i - 1 >= 0) chmax(f01[i][j], f01[i - 1][j] + a[i][j]);
            if (j + 1 < m) chmax(f01[i][j], f01[i][j + 1] + a[i][j]);
        }
    }
    for (int i = n - 1; i >= 0; i --) {
        for (int j = 0; j < m; j ++) {
            f10[i][j] = a[i][j];
            if (i + 1 < n) chmax(f10[i][j], f10[i + 1][j] + a[i][j]);
            if (j - 1 >= 0) chmax(f10[i][j], f10[i][j - 1] + a[i][j]);
        }
        for (int j = m - 1; j >= 0; j --) {
            f11[i][j] = a[i][j];
            if (i + 1 < n) chmax(f11[i][j], f11[i + 1][j] + a[i][j]);
            if (j + 1 < m) chmax(f11[i][j], f11[i][j + 1] + a[i][j]);
        }
    }

    ll res = 0;
    
    for (int i = 1; i + 1 < n; i ++) {
        for (int j = 1; j + 1 < m; j ++) {
            chmax(res, f00[i - 1][j] + f11[i + 1][j] + f10[i][j - 1] + f01[i][j + 1]);
            chmax(res, f00[i][j - 1] + f11[i][j + 1] + f10[i + 1][j] + f01[i - 1][j]);
        }
    }
    cout << res << endl;
}