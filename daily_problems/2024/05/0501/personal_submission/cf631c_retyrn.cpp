int n, m;

void solve() {
    // 前面的较小的操作会被后面较大的操作覆盖
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    vector<pii> op;
    while (m --) {
        int x, y;
        cin >> x >> y;
        while (!em(op) and op.back().se <= y) op.pop_back();
        op.push_back(mpr(x, y));
    }
    m = sz(op);
    multiset<int> S;
    vector<int> b(a.begin(), a.begin() + op[0].se);
    sort(all(b));
    int st = 0, ed = sz(b) - 1;
    
    
    for (int i = 0; i < m - 1; i ++) {
        int type = op[i].fi;
        if (type == 1) {
            // 取大数
            for (int j = op[i].se - 1; j >= op[i + 1].se; j --) {
                a[j] = b[ed --];
            }
        }
        else {
            // 取小数
            for (int j = op[i].se - 1; j >= op[i + 1].se; j --) {
                a[j] = b[st ++];
            }
        }
    }
    if (op.back().fi == 1) {
        for (int i = 0; i < op.back().se; i ++) {
            a[i] = b[st ++];
        }
    }
    else {
        for (int i = 0; i < op.back().se; i ++) {
            a[i] = b[ed --];
        }
    }
        
    cout << a << endl;
}