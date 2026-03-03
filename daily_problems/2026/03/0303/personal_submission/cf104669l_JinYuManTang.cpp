void solve() {
    i64 a, b;
    cin >> a >> b;
    i64 tot = (a + a + b - 1) * b / 2;

    auto check = [&](i64 g) -> bool {
        for (i64 sz = 1; sz <= b / 2; sz++) {
            i64 mn = a * sz + sz * (sz - 1) / 2;
            i64 mx = a * sz + (b - 1 + b - sz) * sz / 2;
            if (mx / g * g >= mn) {
                return true;
            }
        }
        return false;
    };

    i64 res = 0;
    for (i64 g = 1; g * g <= tot; g++) {
        if (tot % g == 0) {
            if (check(g)) {
                chmax(res, g);
            }
            if (check(tot / g)) {
                chmax(res, tot / g);
            }
        }
    }
    cout << res << '\n';
}
