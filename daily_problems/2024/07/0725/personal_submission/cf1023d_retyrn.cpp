int n, m;

void solve() {
    cin >> n >> m;
    // 大数必须在小数的包围中 不存在小数在大数之间
    // 必须有最大数
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> pos(m + 1);
    
    for (int i = 0; i < n; i ++) {
        int x = a[i];
        pos[x].pbk(i);
    }
    
    if (pos[m].empty()) {
        if (em(pos[0])) {
            cout << "NO" << endl;
            return;
        }
        auto t = pos[0].back();
        pos[0].pop_back();
        a[t] = m;
        pos[m].push_back(t);
    }
    
    set<int> S;
    for (int i = 1; i <= m; i ++) {
        if (pos[i].empty()) continue;
        int l = pos[i].front(), r = pos[i].back();
        auto it = S.ub(l);
        if (it != S.end() and *it < r) {
            cout << "NO" << endl;
            return;
        }
        for (auto x : pos[i]) {
            S.insert(x);
        }
    }
    if (a[0] == 0) {
        a[0] = 1;
    }
    for (int i = 1; i < n; i ++) {
        if (a[i] == 0) a[i] = a[i-1];
    }
    cout << "YES" << endl;
    cout << a << endl;
}