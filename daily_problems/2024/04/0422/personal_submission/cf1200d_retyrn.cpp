int n, k;
int b[maxn][maxn];

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

void solve() {
    cin >> n >> k;
    vector<string> g(n);
    cin >> g;
    vector<pii> row(n, mpr(-1, -1)), col(n, mpr(-1, -1));
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (g[i][j] == 'B') {
                if (row[i].fi == -1) row[i].fi = j + 1;
                row[i].se = max(row[i].se, j + 1);
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (g[j][i] == 'B') {
                if (col[i].fi == -1) col[i].fi = j + 1;
                col[i].se = max(col[i].se, j + 1);
            }
        }
    }
    
    // 计算每行的贡献 计算左上角的范围
    for (int i = 0; i < n; i ++) {
        if (row[i].fi == -1) {
            insert(1, 1, n, n, 1);
            continue;
        }
        if (row[i].se - row[i].fi + 1 > k) continue;
        int x1 = max(1, i + 1 - k + 1);
        int y1 = max(1, row[i].se - k + 1);
        int x2 = min(i + 1, n - k + 1);
        int y2 = min(row[i].fi, n - k + 1);
        if (x1 <= x2 and y1 <= y2) {
            insert(x1, y1, x2, y2, 1);
        }
    }
    
    // 计算每列的贡献 计算左上角的范围
    for (int i = 0; i < n; i ++) {
        if (col[i].fi == -1) {
            insert(1, 1, n, n, 1);
            continue;
        }
        if (col[i].se - col[i].fi + 1 > k) continue;
        int y1 = max(1, i + 1 - k + 1);
        int x1 = max(1, col[i].se - k + 1);
        int y2 = min(i + 1, n - k + 1);
        int x2 = min(col[i].fi, n - k + 1);
        if (x1 <= x2 and y1 <= y2) {
            insert(x1, y1, x2, y2, 1);
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            res = max(res, b[i][j]);
        }
    }
    cout << res << endl;
}