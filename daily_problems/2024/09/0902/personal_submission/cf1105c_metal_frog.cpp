void solve() {
    ll l[2], r[2], t[2];
    cin >> l[0] >> r[0] >> t[0];
    cin >> l[1] >> r[1] >> t[1];
    if (l[0] > l[1]) {
        swap(l[0], l[1]);
        swap(r[0], r[1]);
        swap(t[0], t[1]);
    }
    ll d = __gcd(t[0], t[1]);
    ll k = (l[1] - l[0]) / d;
    if ((l[1] - l[0]) % d == 0) {
        cout << min(r[0] - l[0], r[1] - l[1]) + 1LL << "\n";
    } else {
        ll ans = min(r[0] + k * d, r[1]) - l[1] + 1LL;
        ans = max(ans, 0LL);
        ll tmp = min(r[1], r[0] + (k + 1) * d) - max(l[0] + (k + 1) * d, l[1]) + 1LL;
        ans = max(ans, tmp);
        cout << ans << "\n";
    }
}
