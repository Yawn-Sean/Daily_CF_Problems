int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        a[i] = y;
    }
    sort(all(a), greater<int>());
    
    auto check = [&](int x) {
        if (x & 1) {
            ll need = (ll)x * (x - 1) / 2;
            return (need <= n - 1);
        }
        ll need = (ll)x * (x - 1) / 2 + (x - 2) / 2;
        return need <= n - 1;
    };
    
    int cnt = 0;
    for (int i = 1; i <= m; i ++) {
        if (check(i)) chmax(cnt, i);
    }
    
    ll ans = 0;
    for (int i = 0; i < cnt; i ++) {
        ans += a[i];
    }
    cout << ans << endl;
}