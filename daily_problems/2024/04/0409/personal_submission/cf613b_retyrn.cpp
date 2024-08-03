int n, A, cf, cm;
ll m;

void solve() {
    cin >> n >> A >> cf >> cm >> m;
    vector<pii> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(all(a));
    
    vector<ll> s(n + 1, 0ll);
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i - 1].fi;
    }
    
    // 枚举几个满级
    if ((ll)A * n - s[n] <= m) {
        cout << (ll)n * cf + (ll)A * cm << endl;
        for (int i = 0; i < n; i ++) {
            cout << A << ' ';
        }
        cout << endl;
        return;
    }
    
    auto search = [&](int len, ll cost) {
        int l = a[0].fi, r = A - 1;
        while (l < r) {
            auto mid = (l + r + 1) >> 1;
            int idx = lb(a.begin(), a.begin() + len, mpr(mid, -1)) - a.begin();
            // idx个需要补
            ll need = (ll)mid * idx - s[idx];
            if (need <= cost) l = mid;
            else r = mid - 1;
        }
        return l;
    };
    
    ll res = 0;
    int mx_num = 0, down = 0;
    for (int i = 0; i < n; i ++) {
        // 让后i个变成满级
        ll need = (ll)A * i - (s[n] - s[n - i]);
        if (need > m) break;
        // 剩下的用来提升下限
        int low = search(n - i, m - need);
        ll ans = (ll)i * cf + (ll)low * cm;
        // dbg(i, low, ans, need, m - need);
        if (ans > res) {
            res = ans;
            mx_num = i;
            down = low;
        }
    }
    cout << res << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i ++) {
        if (i >= n - mx_num) {
            v[a[i].se] = A;
        }
        else {
            v[a[i].se] = max(down, a[i].fi);
        }
    }
    cout << v << endl;
}