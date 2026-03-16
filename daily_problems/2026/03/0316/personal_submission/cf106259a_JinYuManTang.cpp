void solve() {
    int n, m, r1, c1, r2, c2;
    cin >> n >> m >> r1 >> c1 >> r2 >> c2;
    r1--, r2--, c1--, c2--;
    bool ok = true;
    if (m * n % 2 or (r1 + c1 - r2 - c2) % 2 == 0) {
        ok = false;
    }
    if (n == 1 or m == 1) {
        if (m == 1) {
            swap(m, n), swap(r1, c1), swap(r2, c2);
        }
        if (c1 > c2) {
            swap(c1, c2);
        }
        if (c1 % 2 or (c2 - c1 + 1) % 2 or (m - 1 - c2) % 2) {
            ok = false;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}
