int n, m;

void solve() {
    cin >> n >> m;
    vector<string> g(n);
    cin >> g;
    PrefixSum2D ps(n, m, g);
    
    if (ps.sum(1, 1, n, m) == 0) {
        cout << "MORTAL" << endl;
        return;
    }
    if (ps.sum(1, 1, n, m) == n * m) {
        cout << 0 << endl;
        return;
    }
    
    int cmn = inf, cmx = -1, rmn = inf, rmx = -1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == 'P') {
                chmin(cmn, j), chmax(cmx, j);
                chmin(rmn, i), chmax(rmx, i);
            }
        }
    }
    
    if (g[0][0] == 'A' or g[0][m-1] == 'A' or g[n-1][0] == 'A' or g[n-1][m-1] == 'A') {
        if (n == 1 or m == 1) {
            cout << 1 << endl;
            return;
        }
    }
    // 看能不能一次
    for (int i = 0; i < n; i ++) {
        if (rmn <= i and i <= rmx) continue;
        if (ps.sum(i + 1, cmn + 1, i + 1, cmx + 1) == cmx - cmn + 1) {
            cout << 1 << endl;
            return;
        }
    }
    for (int i = 0; i < m; i ++) {
        if (cmn <= i and i <= cmx) continue;
        if (ps.sum(rmn + 1, i + 1, rmx + 1, i + 1) == rmx - rmn + 1) {
            cout << 1 << endl;
            return;
        }
    }
    
    if (g[0][0] == 'A' or g[0][m-1] == 'A' or g[n-1][0] == 'A' or g[n-1][m-1] == 'A') {
        cout << 2 << endl;
        return;
    }
    for (int i = rmn; i <= rmx; i ++) {
        if (ps.sum(i + 1, cmn + 1, i + 1, cmx + 1) == cmx - cmn + 1) {
            cout << 2 << endl;
            return;
        }
    }
    for (int i = cmn; i <= cmx; i ++) {
        if (ps.sum(rmn + 1, i + 1, rmx + 1, i + 1) == rmx - rmn + 1) {
            cout << 2 << endl;
            return;
        }
    }
    
    // 边上有a就是3
    
    if (ps.sum(1, 1, 1, m) > 0 or ps.sum(n, 1, n, m) > 0 or ps.sum(1, 1, n, 1) > 0 or ps.sum(1, m, n, m) > 0) {
        cout << 3 << endl;
    }
    else {
        cout << 4 << endl;
    }
    
}