int n;

void solve() {
    cin >> n;
    vector<string> g(n);
    cin >> g;
    
    vector<int> row0(n), col0(n);
    int res = 0;
    
    for (int i = 0; i < n; i ++) {
        for (int j = n - 1; j > i; j --) {
            if (g[i][j] - '0' != (row0[i] ^ col0[j])) {
                row0[i] ^= 1;
                col0[j] ^= 1;
                res += 1;
            }
        }
    }
    
    vector<int> row1(n), col1(n);
    
    for (int i = n - 1; i >= 0; i --) {
        for (int j = 0; j < i; j ++) {
            if (g[i][j] - '0' != (row1[i] ^ col1[j])) {
                row1[i] ^= 1;
                col1[j] ^= 1;
                res += 1;
            }
        }
    }
    
    for (int i = 0; i < n; i ++) {
        if (g[i][i] - '0' != (row0[i] ^ row1[i] ^ col0[i] ^ col1[i])) {
            res += 1;
        }
    }
    cout << res << endl;
}