int n, m;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    cin >> m;
    vector<pii> q(m);
    cin >> q;
    vector<int> id(m);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return q[x].se < q[y].se;
    });
    
    int k = 0, base = (int)sqrt(n);
    vector<ll> s(n + 1);
    vector<ll> res(m);
    
    auto init = [&]() {
        fill(all(s), 0);
        for (int i = 1; i <= n; i ++) {
            s[i] += a[n - i];
            if (i - k >= 0) s[i] += s[i - k];
        }
    };
    
    for (auto idx : id) {
        int start = q[idx].fi - 1, step = q[idx].se;
        if (step <= base) {
            if (step > k) {
                k = step;
                init();
            }
            res[idx] = s[n - start];
        }
        else {
            ll ans = 0;
            for (int i = start; i < n; i += step) {
                ans += a[i];
            }
            res[idx] = ans;
        }
    }
    for (auto x : res) {
        cout << x << endl;
    }
}