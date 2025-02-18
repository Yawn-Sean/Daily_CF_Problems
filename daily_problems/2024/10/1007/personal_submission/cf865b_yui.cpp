#define int i64

void solve() {
    int n, m;
    cin >> n >> m;
    vec<int> s(n), a(n), b(n);
    vec<pair<int, int>> ab, ba;
    int tot = 0, md = 1e9;
    int ans = 0, ca = 0, cb = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> a[i] >> b[i];
        tot += s[i];
        if (a[i] > b[i]) {
            ab.push_back({a[i] - b[i], s[i]});
            ans += a[i] * s[i];
            ca += s[i];
        } else {
            ba.push_back({b[i] - a[i], s[i]});
            ans += b[i] * s[i];
            cb += s[i];
        }
    }
    int cnt = (tot + m - 1) / m;
    ca %= m, cb %= m;

    if (ca != 0 && cb != 0 && ca + cb <= m) {
        int ans1 = ans, ans2 = ans;
        ranges::sort(ab);
        ranges::sort(ba);

        for (auto &[v, cnt] : ab) {
            int c = min(ca, cnt);
            ca -= c;
            ans1 -= c * v;
        }
        for (auto &[v, cnt] : ba) {
            int c = min(cb, cnt);
            cb -= c;
            ans2 -= c * v;
        }

        cout << max(ans1, ans2) << '\n';
        return;
    }

    cout << ans << '\n';
}
