int n, m;
int a[N][N];
int dp0[N][N], dp1[N][N], dp2[N][N], dp3[N][N];

void solve1() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = 0;
            if (i > 0) x = max(x, dp0[i - 1][j]);
            if (j > 0) x = max(x, dp0[i][j - 1]);
            dp0[i][j] = x + a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            int x = 0;
            if (i > 0) x = max(x, dp1[i - 1][j]);
            if (j < m - 1) x = max(x, dp1[i][j + 1]);
            dp1[i][j] = x + a[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            int x = 0;
            if (i < n - 1) x = max(x, dp2[i + 1][j]);
            if (j > 0) x = max(x, dp2[i][j - 1]);
            dp2[i][j] = x + a[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int x = 0;
            if (i < n - 1) x = max(x, dp3[i + 1][j]);
            if (j < m - 1) x = max(x, dp3[i][j + 1]);
            dp3[i][j] = x + a[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            res = max(res, dp0[i - 1][j] + dp1[i][j + 1] + dp2[i][j - 1] + dp3[i + 1][j]);
            res = max(res, dp0[i][j - 1] + dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j + 1]);
        }
    }
    cout << res << "\n";
}   
