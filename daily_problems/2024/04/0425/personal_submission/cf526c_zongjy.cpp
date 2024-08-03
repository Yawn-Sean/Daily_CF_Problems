void solve() {
    i64 C, hb, hr, wb, wr;
    cin >> C >> hr >> hb >> wr >> wb;
    i64 ans = 0;
    for (i64 i = 0; i * i <= C; i++) {
        if (C >= i * wb) ans = max(i * hb + (C - i * wb) / wr * hr, ans);
        if (C >= i * wr) ans = max(i * hr + (C - i * wr) / wb * hb, ans);
    }
    cout << ans << '\n';
}