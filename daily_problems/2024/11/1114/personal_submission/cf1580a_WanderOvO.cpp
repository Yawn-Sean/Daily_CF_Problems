int n, m;
int grid[M][M], cnt[M], calc[M];

void meibao() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j] - '0';
        }
    }
    int res = n * m;
    for (int i = 0; i <= n - 5; i++) {
        for (int j = 0; j < m; j++) {
            cnt[j] = 0;
        }

        for (int j = i + 1; j < i + 4; j++) {
            for (int k = 0; k < m; k++) {
                cnt[k] += grid[j][k];
            }
        }

        for (int j = i + 4; j < n; j++) {
            for (int k = 0; k < m; k++) {
                calc[k] = cnt[k];
            }
            for (int k = 1; k < m; k++) {
                calc[k] += 2 - grid[i][k] - grid[j][k];
            }
            for (int k = 1; k < m; k++) {
                calc[k] += calc[k - 1];
            }

            int cur = n * m;
            for (int k = m - 1; k >= 3; k--) {
                cur = min(cur, calc[k - 1] + j - i - 1 - cnt[k]);
                res = min(res, cur - calc[k - 3] + j - i - 1 - cnt[k - 3]);
            }
            for (int k = 0; k < m; k++) {
                cnt[k] += grid[j][k];
            }
        }
    }
    cout << res << "\n";
}
