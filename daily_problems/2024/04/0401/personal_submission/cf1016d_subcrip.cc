// core part
void solve() {
    read(int, n, m);
    readvec(int, a, n);
    readvec(int, b, m);
    vector<vector<int>> res(n, vector<int>(m));
    auto get = [] (int x, int pos) -> int {
        return (x >> pos) & 1;
    };
    auto work = [&] (int pos, int x, int y) -> void {
        if (x == n - 1) {
            for (int j = y; j < m; ++j) {
                res[x][j] |= get(b[j], pos) << pos;
            }
        } else if (y == m - 1) {
            for (int i = x; i < n; ++i) {
                res[i][y] |= get(a[i], pos) << pos;
            }
        } else {
            res[x][y] |= 1 << pos;
            if (get(a[x], pos) == 0) {
                res[x][y + 1] |= 1 << pos;
                b[y + 1] ^= 1 << pos;
            }
            if (get(b[y], pos) == 0) {
                res[x + 1][y] |= 1 << pos;
                a[x + 1] ^= 1 << pos;
            }
        }
    };
    for (int pos = 0;pos < 30; ++pos) {
        int x = 0, y = 0;
        int row = 0, col = 0;
        for (int i = 0; i < n; ++i) row ^= get(a[i], pos);
        for (int j = 0; j < m; ++j) col ^= get(b[j], pos);
        if (row != col) {
            cout << "NO\n";
            return;
        }
        while (1) {
            work(pos, x, y);
            if (x == n - 1 || y == m - 1) break;
            x += 1, y += 1;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << res[i][j] << " \n"[j + 1 == m];
        }
    }
}

