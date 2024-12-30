void Solve() {
    int n, q, m;cin >> n >> q >> m;
    vector s(m + 1, vector(101, vector<int>(101)));
    for (int i = 1;i <= n;i++) {
        int x, y, z;cin >> x >> y >> z;
        s[z][x][y] += 1;
    }
    for (int i = 0;i <= m;i++) {
        for (int j = 1;j <= 100;j++) {
            for (int k = 1;k <= 100;k++) {
                s[i][j][k] += s[i][j - 1][k] + s[i][j][k - 1] - s[i][j - 1][k - 1];
            }
        }
    }
    auto gsum = [&](int p, int a, int b, int c, int d) {
        return s[p][c][d] - s[p][a - 1][d] - s[p][c][b - 1] + s[p][a - 1][b - 1];
        };
    while (q--) {
        int t, a, b, c, d;cin >> t >> a >> b >> c >> d;
        int res = 0;
        for (int i = 0;i <= m;i++) {
            int ni = (i + t) % (m + 1);
            res += gsum(i, a, b, c, d) * ni;
        }
        cout << res << endl;
    }
}
