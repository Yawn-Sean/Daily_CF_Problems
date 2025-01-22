int n, m;

void solve() {
    cin >> n >> m;
    set<pii> S;
    vector<int> a(n * 2 + 1);
    for (int i = 1; i <= n * 2; i ++) {
        cin >> a[i];
        S.insert({a[i], i});
    }
    vector<int> p(n * 2 + 1, -1);
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        p[x] = y;
        p[y] = x;
    }
    // 先找有限制的人
    vector<pii> ps;
    for (int i = 1; i <= n * 2; i ++) {
        if (p[i] > i) {
            int x = i, y = p[i];
            if (a[x] < a[y]) swap(x, y);
            ps.emplace_back(x, y);
        }
    }
    
    auto first = [&]() -> void {
        for (auto [x, y] : ps) {
            if (p[x] < 0) continue;
            cout << x << endl;
            cout.flush();
            int choose;
            cin >> choose;
            p[y] = -1, p[x] = -1;
            S.erase({a[y], y});
            S.erase({a[x], x});
        }
        while (sz(S)) {
            auto t = S.rbegin()->se;
            S.erase({a[t], t});
            cout << t << endl;
            cout.flush();
            if (em(S)) break;
            int x;
            cin >> x;
            S.erase({a[x], x});
        }
    };
    
    int t;
    cin >> t;
    
    if (t == 1) {
        first();
    }
    else {
        for (int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            if (p[x] == -1) {
                S.erase({a[x], x});
                first();
                break;
            }
            else {
                int y = p[x];
                S.erase({a[x], x});
                S.erase({a[y], y});
                cout << y << endl;
                cout.flush();
                p[x] = -1;
                p[y] = -1;
            }
        }
    }
}