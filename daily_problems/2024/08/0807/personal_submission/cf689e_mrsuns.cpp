void Solve() {
    int n, k;cin >> n >> k;
    vector<array<int, 2>> e(n + 1);vector<int> a = { 0 };
    for (int i = 1;i <= n;i++) {
        int l, r;cin >> l >> r;
        e[i] = { l,r };
        a.push_back(l - 1);a.push_back(l);a.push_back(l + 1);
        a.push_back(r - 1);a.push_back(r);a.push_back(r + 1);
    }
    sort(a.begin() + 1, a.end());
    a.erase(unique(a.begin() + 1, a.end()), a.end());
    int m = a.size() - 1;
    vector<int> b(m + 2);
    for (int i = 1;i <= n;i++) {
        auto [l, r] = e[i];
        int idl = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        int idr = lower_bound(a.begin() + 1, a.end(), r) - a.begin();
        b[idl]++, b[idr + 1]--;
    }
    for (int i = 1;i <= m;i++) {
        b[i] += b[i - 1];
    }
    auto norm = [&](int x) {
        return (x % MOD + MOD) % MOD;
        };
    int res = 0;
    for (int i = 1;i <= m;) {
        int ks = i;
        i++;
        while (i <= m && b[i] == b[i - 1]) i++;
        int L = ks, R = i - 1;
        res = (res + norm(a[R] - a[L] + 1) * comb(b[L], k) % MOD) % MOD;
    }
    cout << res << endl;
}
