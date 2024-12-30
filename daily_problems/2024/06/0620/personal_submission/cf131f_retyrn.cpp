int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<string> g(n);
    cin >> g;
    vector<vector<int>> f(n, vector<int>(m, 0));
    for (int i = 1; i + 1 < n; i ++) {
        for (int j = 1; j + 1 < m; j ++) {
            if (g[i][j] == '1' and g[i-1][j] == '1' and g[i+1][j] == '1' and g[i][j-1] == '1' and g[i][j+1] == '1') {
                f[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (j) f[i][j] += f[i][j - 1];
        }
    }
    
    auto get = [&](int x, int y1, int y2) {
        return f[x][y2] - (y1 ? f[x][y1-1] : 0);
    };
    
    ll res = 0;
    for (int y1 = 0; y1 < m; y1 ++) {
        for (int y2 = y1 + 2; y2 < m; y2 ++) {
            ll cur = 0;
            bool ok = false;
            for (int i = 1, j = 0; i < n; i ++) {
                cur += get(i - 1, y1 + 1, y2 - 1);
                if (cur >= k) ok = true;
                while (cur >= k) {
                    cur -= get(j + 1, y1 + 1, y2 - 1);
                    j ++;
                }
                if (ok) res += j;
            }
        }
    }
    cout << res << endl;
}