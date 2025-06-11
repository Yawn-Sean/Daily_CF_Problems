int n, m;

void solve() {
    cin >> n >> m;
    // 边为0的 要不同正负
    // 边为1的 要同正负
    TwoSat ts(n);
    
    while (m --) {
        int x, y, w;
        cin >> x >> y >> w;
        x --, y --;
        if (w == 0) {
            // 不同正负
            ts.add(x * 2, y * 2 + 1);
            ts.add(x * 2 + 1, y * 2);
        }
        else {
            ts.add(x * 2, y * 2);
            ts.add(x * 2 + 1, y * 2 + 1);
        }
    }
    if (!ts.satisfiable()) {
        cout << "Impossible" << endl;
        return;
    }
    vector<int> res;
    auto ans = ts.answer();
    for (int i = 0; i < n; i ++) {
        if (ans[i]) res.push_back(i + 1);
    }
    cout << sz(res) << endl;
    cout << res << endl;
    
}