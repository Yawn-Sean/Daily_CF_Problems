void Solve() {
    int n, m;cin >> n >> m;
    vector a(m + 1, vector<int>(n + 1)), pos(m + 1, vector<int>(n + 1));
    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
            pos[i][a[i][j]] = j;
        }
    }
    int res = 0;
    for (int i = 1, r = 1;i <= n;i++) {
        r = max(r, i);
        while (r < n) {
            auto ck = [&]() {
                for (int j = 2;j <= m;j++) {
                    if (pos[j][a[1][r + 1]] - pos[j][a[1][r]] != 1) return 0;
                }
                return 1;
                };
            if (ck()) {
                r++;
            }
            else break;
        }
        res += r - i + 1;
    }
    cout << res << endl;
}
