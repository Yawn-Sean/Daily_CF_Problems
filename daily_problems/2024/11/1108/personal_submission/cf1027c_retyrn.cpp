int n;

void solve() {
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mp[x] += 1;
    }
    
    vector<pii> a;
    int last = -1;
    for (auto [k, v] : mp) {
        if (v > 1) {
            if (last > 0) a.emplace_back(last, k);
            last = k;
        }
        if (v >= 4) {
            cout << k << ' ' << k << ' ' << k << ' ' << k << endl;
            return;
        }
    }
    
    sort(all(a), [](pii& x, pii& y) {
        return (ll)(x.fi + x.se) * (x.fi + x.se) * y.fi * y.se < (ll)(y.fi + y.se) * (y.fi + y.se) * x.fi * x.se;
    });
    
    cout << a[0] << ' ' << a[0] << endl;
}