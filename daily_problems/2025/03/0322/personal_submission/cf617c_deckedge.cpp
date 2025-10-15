
void solve() {
    int n = read(), x1 = read(), y1 = read(), x2 = read(), y2 = read();
    ve<pi> a(n);
    rep(i, 0, n) {
        int x = read(), y = read();
        i64 dx = x - x1, dy = y - y1;
        a[i].fi = dx * dx + dy * dy;
        dx = x - x2, dy = y - y2;
        a[i].se = dx * dx + dy * dy; 
    }
    sort(all(a));
    i64 mn = 1e18, mx = 0;
    rep(i, 0, n) {
        i64 r1 = a[i].fi, r2 = 0;
        mx = max(mx, a[i].se);
        rep(j, i + 1, n) {
            r2 = max(r2, a[j].se);
        }
        mn = min(mn, r1 + r2);
    }
    
    mn = min(mn, mx);
    cout << mn << '\n';
}

