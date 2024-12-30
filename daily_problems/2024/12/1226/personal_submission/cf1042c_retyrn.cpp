int n;

void solve() {
    cin >> n;
    vector<vector<pii>> a(3);
    // -:0 0:1 +:2
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        int flag = (x == 0 ? 1 : (x < 0 ? 0 : 2));
        a[flag].emplace_back(x, i + 1);
    }
    for (auto& vec : a) {
        sort(all(vec), [](pii& x, pii& y) {
            return abs(x.fi) < abs(y.fi);
        });
    }
    
    auto out = [&a](int del) -> void {
        int root = -1;
        for (const auto& vec : a) {
            for (const auto& [_, id] : vec) {
                if (id == del) {
                    cout << 2 << ' ' << del << endl;
                    continue;
                }
                if (root == -1) {
                    root = id;
                    continue;
                }
                cout << 1 << ' ' << id << ' ' << root << endl;
            }
        }
    };
    
    if (sz(a[0]) % 2) {
        // 要变成负数了, 负数肯定要删掉
        // 走之前带走所有的0
        int root = a[0][0].se;
        while (sz(a[1])) {
            if (em(a[2]) and sz(a[0]) == 1 and sz(a[1]) == 1) break;
            auto id = a[1].back().se;
            a[1].pop_back();
            cout << 1 << ' ' << id << ' ' << root << endl;
        }
        out(root);
        return;
    }
    
    // 不会负数, 把0全部带走
    if (sz(a[1])) {
        int root = a[1][0].se;
        for (int i = 1; i < sz(a[1]); i ++) {
            auto id = a[1][i].se;
            cout << 1 << ' ' << id << ' ' << root << endl;
        }
        if (sz(a[1]) == n) return;
        cout << 2 << ' ' << root << endl;
        a[1].clear();
        out(-1);
        return;
    }
    
    out(-1);
}