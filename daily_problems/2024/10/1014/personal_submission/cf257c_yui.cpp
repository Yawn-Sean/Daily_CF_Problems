#define int i64

using f64 = long double;

void solve() {
    int n;
    cin >> n;
    vec<pair<int, int>> a(n);
    vec<f64> rec(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i].first >> a[i].second;
        rec[i] = atan2(a[i].second, a[i].first);
    }
    ranges::sort(rec);
    f64 ans = 400;
    for (int i = 0; i < n; i++) {
        f64 a1 = rec[i] * 180.L / numbers::pi;
        f64 a2 = rec[(i + 1) % n] * 180.L / numbers::pi;
        f64 cur = fabs(a1 - a2);
        if (i != n - 1) cur = 360.L - cur;
        chmin(ans, cur);
    }

    cout << ans << '\n';

}
