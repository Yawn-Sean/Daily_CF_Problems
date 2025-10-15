void Solve() {
    int n, m, q;cin >> n >> m >> q;
    vector<string> s(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> s[i];s[i] = ' ' + s[i];
    }
    vector<vector<int>> pre(n + 1, vector<int>(m + 1));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + (s[i][j] == '1');
        }
    }
    vector res(n + 2, vector(m + 2, vector(n + 1, vector<int>(m + 1))));
    for (int a = 1;a <= n;a++) {
        for (int b = 1;b <= m;b++) {
            for (int c = a;c <= n;c++) {
                for (int d = b;d <= m;d++) {
                    int sum = pre[c][d] + pre[a - 1][b - 1] - pre[c][b - 1] - pre[a - 1][d];
                    if (sum == 0) {
                        res[a][b][c][d] = 1;
                        //cout << a << " " << b << ' ' << c << ' ' << d << endl;
                    }
                }
            }
        }
    }
 
    for (int a = n;a >= 1;a--) {
        for (int b = m;b >= 1;b--) {
            for (int c = 1;c <= n;c++) {
                for (int d = 1;d <= m;d++) {
                    res[a][b][c][d] += res[a + 1][b][c][d];
                }
            }
        }
    }
    for (int a = n;a >= 1;a--) {
        for (int b = m;b >= 1;b--) {
            for (int c = 1;c <= n;c++) {
                for (int d = 1;d <= m;d++) {
                    res[a][b][c][d] += res[a][b + 1][c][d];
                }
            }
        }
    }
    for (int a = n;a >= 1;a--) {
        for (int b = m;b >= 1;b--) {
            for (int c = 1;c <= n;c++) {
                for (int d = 1;d <= m;d++) {
                    res[a][b][c][d] += res[a][b][c - 1][d];
                }
            }
        }
    }
    for (int a = n;a >= 1;a--) {
        for (int b = m;b >= 1;b--) {
            for (int c = 1;c <= n;c++) {
                for (int d = 1;d <= m;d++) {
                    res[a][b][c][d] += res[a][b][c][d - 1];
                }
            }
        }
    }
 
    while (q--) {
        int a, b, c, d;cin >> a >> b >> c >> d;
        //a<=x1,b<=y1,x2<=c,y2<=d
        cout << res[a][b][c][d] << endl;
    }
}
