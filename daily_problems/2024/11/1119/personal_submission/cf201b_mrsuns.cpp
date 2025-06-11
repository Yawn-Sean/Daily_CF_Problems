void Solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) cin >> a[i][j];
    }
    vector<int> sum_row(n + 1), sum_col(m + 1);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) sum_row[i] += a[i][j];
    }
    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) sum_col[i] += a[j][i];
    }
    vector<int> p(max(n, m) + 1);p[1] = 2;
    for (int i = 2;i <= max(n, m);i++) {
        p[i] = p[i - 1] + 4;
    }
    vector<int> row(n + 1);
    for (int i = 0;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            row[i] += (p[j] - i * 4) * (p[j] - i * 4) * sum_row[j];
        }
    }
    vector<int> col(m + 1);
    for (int i = 0;i <= m;i++) {
        for (int j = 1;j <= m;j++) {
            col[i] += (p[j] - i * 4) * (p[j] - i * 4) * sum_col[j];
        }
    }
    int res = 1e18, x = -1, y = -1;
    for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= m;j++) {
            int t = row[i] + col[j];
            if (t < res) {
                res = t;
                x = i, y = j;
            }
        }
    }
    cout << res << endl;
    cout << x << " " << y << endl;
}
