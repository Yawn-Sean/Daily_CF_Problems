int n, m;

void solve() {
    // 不让放在边边上 所以最短路一定是一样的 2条边
    cin >> n >> m;
    vector<string> g(4, string(n, '.'));
    
    // 如果是偶数
    if (m % 2 == 0) {
        cout << "YES" << endl;
        for (int i = 1; i < n - 1 and m > 0; i ++) {
            g[1][i] = g[2][i] = '#';
            m -= 2;
        }
        for (auto& s : g) {
            cout << s << endl;
        }
        return;
    }
    // 如果n是偶数
    if (n % 2 == 0) {
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
    for (int i = 1, j = n - 2; i < j and m >= 2; i ++, j --) {
        g[1][i] = g[1][j] = '#';
        m -= 2;
    }
    if (m & 1) {
        g[1][n / 2] = '#';
        m -= 1;
    }
    for (int i = 1, j = n - 2; i < j and m >= 2; i ++, j --) {
        g[2][i] = g[2][j] = '#';
        m -= 2;
    }
    if (m & 1) {
        g[2][n / 2] = '#';
        m -= 1;
    }
    for (auto& s : g) {
        cout << s << endl;
    }
}