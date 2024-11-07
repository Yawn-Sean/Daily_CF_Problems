int n, m, k;

char get(int x) {
    if (x < 10) return '0' + x;
    if (x < 36) return 'a' + (x - 10);
    return 'A' + (x - 36);
}
void solve() {
    cin >> n >> m >> k;
    vector<string> g(n);
    cin >> g;
    
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cnt += (g[i][j] == 'R');
        }
    }
    
    int base = cnt / k;
    int cnt1 = cnt % k, cnt0 = k - cnt1;
    
    int idx = 0;
    int need = (cnt1 == 0 ? base : base + 1);
    if (need == base + 1) cnt1 --;
    else cnt0 --;
    
    vector<string> res(n, string(m, '#'));
    
    for (int i = 0; i < n; i ++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j ++) {
                res[i][j] = get(idx);
                if (g[i][j] == 'R') {
                    need -= 1;
                    if (need == 0) {
                        need = (cnt1 == 0 ? base : base + 1);
                        if (need == base + 1) cnt1 --;
                        else cnt0 --;
                        if (cnt0 + cnt1 >= 0) idx ++;
                    }
                }
            }
        }
        else {
            for (int j = m - 1; j >= 0; j --) {
                res[i][j] = get(idx);
                if (g[i][j] == 'R') {
                    need -= 1;
                    if (need == 0) {
                        need = (cnt1 == 0 ? base : base + 1);
                        if (need == base + 1) cnt1 --;
                        else cnt0 --;
                        if (cnt0 + cnt1 >= 0) idx ++;
                    }
                }
            }
        }
    }
    
    for (auto& ss : res) {
        cout << ss << endl;
    }
}