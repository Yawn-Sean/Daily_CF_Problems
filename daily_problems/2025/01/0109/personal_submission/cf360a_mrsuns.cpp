void Solve() {
    int n, m;cin >> n >> m;
    vector<array<int, 4>> a(m + 1);
    for (int i = 1;i <= m;i++) {
        int t, l, r, x;cin >> t >> l >> r >> x;
        a[i] = { t,l,r,x };
    }
    vector<int> s(n + 1), res(n + 1, inf);
    for (int i = 1;i <= m;i++) {
        auto [t, l, r, x] = a[i];
        if (t == 1) {
            for (int j = l;j <= r;j++) {
                s[j] += x;
            }
        }
        else {
            for (int j = l;j <= r;j++) {
                res[j] = min(res[j], x - s[j]);
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        if (res[i] < -inf) return cout << "NO\n", void();
    }
    s.assign(n + 1, 0);
    for (int i = 1;i <= m;i++) {
        auto [t, l, r, x] = a[i];
        if (t == 1) {
            for (int j = l;j <= r;j++) {
                s[j] += x;
            }
        }
        else {
            auto ck = [&]() {
                for (int j = l;j <= r;j++) {
                    if (res[j] + s[j] == x) return 1;
                }
                return 0;
                };
            if (!ck()) return cout << "NO\n", void();
        }
    }
    cout << "YES\n";
    for (int i = 1;i <= n;i++) {
        cout << res[i] << ' ';
    }
}
