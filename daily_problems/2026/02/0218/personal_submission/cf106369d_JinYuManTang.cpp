void solve() {
    long double y, x, r;
    cin >> y >> x >> r;
    x = abs(x);
    if (x * x * y * y > (x * x + y * y) * r * r) {
        cout << -1;
        return;
    }
    if (r >= x) {
        cout << 0;
        return;
    }
    long double res = asinl(x * y / (r * hypotl(x, y))) - atan2l(y, x);
    res = res / acos(-1) * 180;
    cout << fixed << setprecision(10) << res;
}
