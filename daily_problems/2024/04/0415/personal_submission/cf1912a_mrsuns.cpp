void Solve() {
    ll x;int k;cin >> x >> k;
    vector<array<ll, 2>> a;
    for (int i = 1;i <= k;i++) {
        int len;cin >> len;
        ll pre = 0, mn = 0, mx = 0;
        ll lstmx = mx;
        for (int j = 1;j <= len;j++) {
            int x; cin >> x;
            pre += x;mx = max(mx, pre);mn = min(mn, pre);
            if (mx > lstmx) {
                a.push_back({ -mn,mx - lstmx });
                lstmx = mx;
            }
        }
    }
    sort(a.begin(), a.end());
    for (auto [cost, val] : a) {
        if (x >= cost) x += val;
        else break;
    }
    cout << x << endl;
}
