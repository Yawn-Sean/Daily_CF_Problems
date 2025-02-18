int n, a, b;

void solve() {
    cin >> n >> a >> b;
    if (a > 1 and b > 1) {
        cout << "NO" << endl;
        return;
    }
    if (a > 1) {
        vector<string> res(n, string(n, '0'));
        for (int i = a; i < n; i ++) {
            res[i][0] = res[0][i] = '1';
        }
        cout << "YES" << endl;
        for (auto& s : res) {
            cout << s << endl;
        }
        return;
    }
    if (b > 1) {
        vector<string> res(n, string(n, '1'));
        for (int i = b; i < n; i ++) {
            res[i][0] = res[0][i] = '0';
        }
        for (int i = 0; i < n; i ++) {
            res[i][i] = '0';
        }
        cout << "YES" << endl;
        for (auto& s : res) {
            cout << s << endl;
        }
        return;
    }
    
    // a = b = 1
    if (n == 2 or n == 3) {
        cout << "NO" << endl;
        return;
    }
    vector<string> res(n, string(n, '0'));
    for (int i = 1; i < n; i ++) {
        res[i-1][i] = res[i][i-1] = '1';
    }
    cout << "YES" << endl;
    for (auto& s : res) {
        cout << s << endl;
    }
}