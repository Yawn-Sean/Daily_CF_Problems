int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    vector<int> b(m);
    cin >> b;
    
    sort(all(a));
    vector<ll> s1(n + 1, 0ll);
    for (int i = 1; i <= n; i ++) {
        s1[i] = s1[i - 1] + a[i - 1];
    }
    sort(all(b));
    vector<ll> s2(m + 1, 0ll);
    for (int i = 1; i <= m; i ++) {
        s2[i] = s2[i - 1] + b[i - 1];
    }
    
    auto cal1 = [&](int x) {
        int idx = lower_bound(all(a), x) - a.begin();
        return (ll)x * idx - s1[idx];
    };
    
    auto cal2 = [&](int x) {
        int idx = upper_bound(all(b), x) - b.begin();
        return s2[m] - s2[idx] - (ll)x * (m - idx);
    };
    
    vector<int> val;
    for (auto x : a) {
        val.pbk(x);
    }
    for (auto x : b) {
        val.pbk(x);
    }
    ll res = inf2;
    for (auto x : val) {
        res = min(cal1(x) + cal2(x), res);
    }
    cout << res << endl;
}