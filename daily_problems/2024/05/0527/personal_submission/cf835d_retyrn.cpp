int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    vector<int> res(n);
    vector<vector<int>> f(n, vector<int>(n, 0)); // f[i][j] s[i:j]的阶数
    for (int i = 0; i < n; i ++) {
        f[i][i] = 1;
        res[0] += 1;
    }
    
    for (int len = 2; len <= n; len ++) {
        for (int i = 0; i + len - 1 < n; i ++) {
            int j = i + len - 1;
            if (s[i] == s[j] and (j == i + 1 or f[i + 1][j - 1])) {
                int x = f[i][i + len / 2 - 1], y = f[j - len / 2 + 1][j];
                f[i][j] = min(x, y) + 1;
                res[f[i][j] - 1] += 1;
            }
        }
    }
    for (int i = n - 2; i >= 0; i --) {
        res[i] += res[i + 1];
    }
    cout << res << endl;
}