using ai3 = array<int, 3>;
int n;

void solve() {
    cin >> n;
    vector<ai3> a(n);
    for (auto& x : a) {
        cin >> x[0] >> x[1] >> x[2];
    }
    vector<int> st(n, true);
    vector<pii> res;
    map<pii, vector<pii>> mp1;
    for (int i = 0; i < n; i ++) {
        int x = a[i][0], y = a[i][1], z = a[i][2];
        mp1[mpr(x, y)].emplace_back(z, i);
    }
    for (auto& [_, p] : mp1) {
        sort(all(p));
        while (sz(p) > 1) {
            int t1 = p.back().se;
            p.pop_back();
            int t2 = p.back().se;
            p.pop_back();
            res.emplace_back(t1 + 1, t2 + 1);
            st[t1] = st[t2] = false;
        }
    }
    
    map<int, vector<pii>> mp2;
    for (int i = 0; i < n; i ++) {
        if (!st[i]) continue;
        int x = a[i][0], y = a[i][1];
        mp2[x].emplace_back(y, i);
    }
    for (auto& [_, p] : mp2) {
        sort(all(p));
        while (sz(p) > 1) {
            int t1 = p.back().se;
            p.pop_back();
            int t2 = p.back().se;
            p.pop_back();
            res.emplace_back(t1 + 1, t2 + 1);
            st[t1] = st[t2] = false;
        }
    }
    
    vector<pii> p;
    for (int i = 0; i < n; i ++) {
        if (!st[i]) continue;
        p.emplace_back(a[i][0], i);
    }
    sort(all(p));
    while (sz(p) > 1) {
        int t1 = p.back().se;
        p.pop_back();
        int t2 = p.back().se;
        p.pop_back();
        res.emplace_back(t1 + 1, t2 + 1);
        st[t1] = st[t2] = false;
    }
    cout << res << endl;
    
}