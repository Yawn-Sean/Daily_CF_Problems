int n;

void solve() {
    vector<pii> a(4);
    map<pii, int> mp;
    
    cin >> a;
    sort(all(a));
    int d = a[2].fi - a[0].fi;
    for (int i = a[0].fi; i <= a[0].fi + d; i ++) {
        for (int j = a[0].se; j <= a[0].se + d; j ++) {
            mp[mpr(i, j)] |= 1;
        }
    }
    
    cin >> a;
    sort(all(a));
    d = a[2].se - a[0].se;
    for (int i = 0; i <= d; i ++) {
        int x = a[0].fi + i, y = a[0].se - i;
        for (int j = 0; j <= d; j ++) {
            mp[mpr(x, y)] |= 2;
            x += 1, y += 1;
        }
    }
    
    for (auto& [k, v] : mp) {
        if (v == 3) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}