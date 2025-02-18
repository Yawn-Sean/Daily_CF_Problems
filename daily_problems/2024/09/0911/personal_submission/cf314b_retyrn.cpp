int n, m, b, d;
string a, c;

void solve() {
    cin >> b >> d;
    cin >> a >> c;
    
    for (auto x : c) {
        if (a.find(x) == string::npos) {
            cout << 0 << endl;
            return;
        }
    }
    
    n = sz(a), m = sz(c);
    vector<int> cnt(m), next(m);
    
    for (int i = 0; i < m; i ++) {
        int x = i, y = 0;
        for (int j = 0; j < n; j ++) {
            if (c[x] == a[j]) {
                x += 1;
                if (x == m) {
                    x = 0;
                    y += 1;
                }
            }
        }
        cnt[i] = y;
        next[i] = x;
    }
    
    // 模拟
    int res = 0, x = 0;
    for (int i = 0; i < b; i ++) {
        res += cnt[x];
        x = next[x];
    }
    cout << res / d << endl;
}