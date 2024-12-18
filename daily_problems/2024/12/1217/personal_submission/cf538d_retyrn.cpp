int n;

void solve() {
    cin >> n;
    vector<string> g(n);
    cin >> g;
    // 先ban掉所有点的操作
    vector<string> res(n * 2 - 1, string(n * 2 - 1, 'x'));
    res[n-1][n-1] = 'o';
    
    vector<pii> os;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (g[i][j] != 'o') continue;
            os.emplace_back(i, j);
            for (int x = 0; x < n; x ++) {
                for (int y = 0; y < n; y ++) {
                    if (g[x][y] == '.') {
                        int dx = x - i, dy = y - j;
                        res[dx + n - 1][dy + n - 1] = '.';
                    }
                }
            }
        }
    }
    
    // 验证所有的x都能从o走到
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (g[i][j] != 'x') continue;
            bool ok = false;
            for (auto [x, y] : os) {
                int dx = i - x, dy = j - y;
                if (res[dx+n-1][dy+n-1] == 'x') {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    
    cout << "YES" << endl;
    // 验证是否可以
    for (auto& ss : res) {
        cout << ss << endl;
    }
}