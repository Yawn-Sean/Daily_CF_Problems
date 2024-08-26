int n, m;
pii e[maxn];

void solve() {
    cin >> n >> m;
    set<pii> S;
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        if (x > y) swap(x, y);
        e[i].fi = x, e[i].se = y;
        S.insert(e[i]);
    }
    
    auto check = [&](int d, int n) {
        for (int i = 0; i < m; i ++) {
            int x = (e[i].fi + d) % n;
            int y = (e[i].se + d) % n;
            if (x > y) swap(x, y);
            auto p = mpr(x, y);
            if (!S.count(p)) return false;
        }
        return true;
    };
    
    int n1 = n;
    for (int d = 2; d <= n / d; d ++) {
        if (n % d) continue;
        while (n % d == 0) n /= d;
        if (check(n1 / d, n1)) {
            cout << "Yes" << endl;
            return;
        }
    }
    if (n > 1) {
        if (check(n1 / n, n1)) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}