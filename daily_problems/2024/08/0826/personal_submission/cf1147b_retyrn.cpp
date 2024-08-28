int n, m;
pii e[maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        if (x > y) swap(x, y);
        e[i].fi = x, e[i].se = y;
    }
    set<pii> S(e, e + m);
    
    vector<int> f = {1};
    for (int i = 2; i <= n / i; i ++) {
        if (n % i) continue;
        f.push_back(i);
        if (n / i != i) f.push_back(n / i);
    }
    
    for (auto d : f) {
        bool ok = true;
        for (int i = 0; i < m; i ++) {
            int x = (e[i].fi + d) % n;
            int y = (e[i].se + d) % n;
            if (x > y) swap(x, y);
            auto p = mpr(x, y);
            if (S.count(p)) {
                continue;
            }
            ok = false;
            break;
        }
        if (ok) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}
