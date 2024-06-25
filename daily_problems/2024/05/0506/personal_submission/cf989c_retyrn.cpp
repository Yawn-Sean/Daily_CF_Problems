int a, b, c, d;
int n = 50;

void solve() {
    cin >> a >> b >> c >> d;
    vector<string> g(n, string(n, '#'));
    for (int i = 0; i < n / 2; i ++) {
        for (int j = 0; j < n / 2; j ++) {
            g[i][j] = 'A';
        }
        for (int j = n / 2; j < n; j ++) {
            g[i][j] = 'B';
        }
    }
    for (int i = n / 2; i < n; i ++) {
        for (int j = 0; j < n / 2; j ++) {
            g[i][j] = 'C';
        }
        for (int j = n / 2; j < n; j ++) {
            g[i][j] = 'D';
        }
    }
    
    a --, b --, c --, d --;
    
    // a 里填 d
    for (int i = 1; i < n / 2 and d > 0; i += 2) {
        for (int j = 1; j < n / 2 and d > 0; j += 2, d --) {
            g[i][j] = 'D';
        }
    }
    // b 里填 a
    for (int i = 1; i < n / 2 and a > 0; i += 2) {
        for (int j = n / 2 + 1; j < n and a > 0; j += 2, a --) {
            g[i][j] = 'A';
        }
    }
    
    // c 里填 b
    for (int i = n / 2 + 1; i < n and b > 0; i += 2) {
        for (int j = 1; j < n / 2 and b > 0; j += 2, b --) {
            g[i][j] = 'B';
        }
    }
    // d 里填 c
    for (int i = n / 2 + 1; i < n and c > 0; i += 2) {
        for (int j = n / 2 + 1; j < n and c > 0; j += 2, c --) {
            g[i][j] = 'C';
        }
    }
    cout << n << ' ' << n << endl;
    for (auto& s : g) {
        cout << s << endl;
    }
}