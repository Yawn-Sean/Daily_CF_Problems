void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= n; j++) {
            mp[i][j] = s[j - 1] == 'B';
        }
    }
    vector<vector<int>> rows(n + 1, vector<int>(n + 1));
    vector<vector<int>> lines(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            rows[i][j] = mp[i][j] + rows[i][j - 1];
            lines[i][j] = mp[i][j] + lines[i - 1][j];
        }
    }
//    debug(rows);
//    debug(lines);
    vector<int> rows1(n + 1), lines1(n + 1);
    for (int i = 1; i <= n; i++) {
        if (rows[i][n] == 0) rows1[i]++;
        if (lines[n][i] == 0) lines1[i]++;
    }
    for (int i = 1; i <= n; i++) {
        rows1[i] += rows1[i - 1];
        lines1[i] += lines1[i - 1];
    }
//    debug(rows1);
//    debug(lines1);
    vector<vector<int>> rows2(n + 1, vector<int>(n + 1));
    vector<vector<int>> lines2(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j + k - 1 <= n) {
                // 对于第i行
                int sums = 0;
                // j  - j + k - 1
                sums += rows[i][j - 1] + rows[i][n] - rows[i][j + k - 1];
                if (!sums) {
                    rows2[i][j] = 1;
                }
            }
            if (i + k - 1 <= n) {
                int sums = 0;
                // i - i+k-1
                sums = lines[i - 1][j] + lines[n][j] - lines[i + k - 1][j];
                if (!sums) {
                    lines2[i][j] = 1;
                }
            }

        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            rows2[i][j] += rows2[i - 1][j];
            lines2[i][j] += lines2[i][j - 1];
        }
    }
//    debug(rows2);
//    debug(lines2);
    int maxs = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= n - k + 1; j++) {
            //  i - i+k - 1
            int a = lines1[i - 1] +
                    lines1[n] - lines1[i + k - 1];
            int b = rows1[j - 1] +
                    rows1[n] - rows1[j + k - 1];
            int c = rows2[i + k - 1][j] - rows2[i - 1][j];
            int d = lines2[i][j + k - 1] - lines2[i][j - 1];
            debug(a, b, c, d);
            int sums = rows1[i - 1] +
                    rows1[n] - rows1[i + k - 1] +
                    lines1[j - 1] +
                    lines1[n] - lines1[j + k - 1] +
                       +rows2[i + k - 1][j] - rows2[i - 1][j] +
                       lines2[i][j + k - 1] - lines2[i][j - 1];
            maxs = max(sums, maxs);
            debug(i, j, sums);
//            debug(i, j, sums);
        }
    }
    cout << maxs << endl;
}
