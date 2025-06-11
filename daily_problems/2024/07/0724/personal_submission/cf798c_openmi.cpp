void solve() {
    int n;
    cin >> n;
    vi a(n);
    in(a);
    int ans = 0, cnt1 = 0, t = a[0];
    rep (i, 1, n) {
        t = gcd(t, a[i]);
        if (t == 1) break;
    }
    if (t > 1) {
        p(1);
        return cout << 0, void();
    }
    a.push_back(0);
    rep (i, 0, n + 1) {
        if (a[i] % 2) {
            cnt1 += 1;
        } else {
            ans += cnt1 / 2 + (cnt1 & 1) * 2;
            cnt1 = 0;
        }
    }
    p(1);
    cout << ans;
}
