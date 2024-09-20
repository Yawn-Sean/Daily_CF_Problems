using f64 = long double;

void solve() {
    int x, y, n;
    cin >> x >> y >> n;
    int p = 1, q = n;
    f64 cmp = 1.L * x / y, diff = 1e9;
    for (int i = 1; i <= n; i++) {
        int l = x * i / y, r = l + 1;
        if (fabs(1.L * l / i - cmp) < diff) {
            diff = fabs(1.L * l / i - cmp);
            p = l;
            q = i;
        }
        if (fabs(1.L * r / i - cmp) < diff) {
            diff = fabs(1.L * r / i - cmp);
            p = r;
            q = i;
        }
        debug(p, q);
    }

    cout << p << '/' << q << '\n';
}
