int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a, b;
    int t;
    cin >> t;
    a.resize(t);
    cin >> a;
    sort(all(a));
    
    cin >> t;
    b.resize(t);
    cin >> b;
    sort(all(b), greater<int>());
    
    vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
    
    for (auto t : a) {
        // 填入的位置 x+y=t
        int mx = 0, x = 0, y = 0;
        for (int cur = t; cur >= 2; cur --) {
            for (int i = max(1, cur - m); i <= n and i <= cur - 1; i ++) {
                int j = cur - i;
                if (f[i][j]) continue;
                if (mx < i + (m + 1 - j)) {
                    mx = i + m + 1 - j;
                    x = i, y = j;
                }
            }
        }
        if (mx == 0) {
            cout << "NO" << endl;
            return;
        }
        f[x][y] = true;
    }
    vector<int> need;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (!f[i][j]) need.pbk(i + m + 1 - j);
        }
    }
    sort(all(need), greater<int>());
    
    for (int i = 0; i < sz(need); i ++) {
        if (b[i] < need[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}