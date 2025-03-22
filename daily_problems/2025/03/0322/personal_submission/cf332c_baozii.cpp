int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    i64 n, x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vll d1(n), d2(n);
    rep(i, 0, n) {
        i64 x, y;
        cin >> x >> y;
        d1[i] = (x - x1) * (x - x1) + (y - y1) * (y - y1);
        d2[i] = (x - x2) * (x - x2) + (y - y2) * (y - y2);
    }
    i64 ans = ranges::max(d2);
    rep(i, 0, n) {
        i64 r1 = d1[i];
        i64 r2 = 0;
        rep(j, 0, n) if (r1 < d1[j]) r2 = max(r2, d2[j]);
        ans = min(ans, r1 + r2);
    }
    cout << ans;
}
