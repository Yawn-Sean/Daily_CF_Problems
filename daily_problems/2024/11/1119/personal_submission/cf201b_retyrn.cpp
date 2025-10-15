int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> row(n), col(m);
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> a[i][j];
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    
    pii res = {0, 0};
    
    ll mn1 = inf2;
    for (int i = 0; i <= n; i ++) {
        int p1 = 4 * i;
        ll cur = 0;
        for (int j = 0; j < n; j ++) {
            int p2 = j * 4 + 2;
            cur += (ll)row[j] * (p1 - p2) * (p1 - p2);
        }
        if (cur < mn1) {
            mn1 = cur;
            res.fi = i;
        }
    }
    
    ll mn2 = inf2;
    for (int i = 0; i <= m; i ++) {
        int p1 = 4 * i;
        ll cur = 0;
        for (int j = 0; j < m; j ++) {
            int p2 = j * 4 + 2;
            cur += (ll)col[j] * (p1 - p2) * (p1 - p2);
        }
        if (cur < mn2) {
            mn2 = cur;
            res.se = i;
        }
    }
    
    cout << (mn1 + mn2) << endl;
    
    cout << res << endl;
}