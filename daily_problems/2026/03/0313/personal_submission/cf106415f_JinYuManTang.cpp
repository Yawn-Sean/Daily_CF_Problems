void solve() {
    int n;
    cin >> n;

    auto query = [&](i64 x, i64 y) -> i64 {
        cout << "? " << x << ' ' << y << endl;
        char c;
        i64 v;
        cin >> c >> v;
        return v;
    };

    auto reply = [&](i64 x) -> void {
        cout << "!" << x << endl;
        char c;
        cin >> c;
    };

    auto f = [&](auto& f, i64 x) -> i64 {
        if ((x & -x) == x) {
            return query(x, x) / 2;
        }
        i64 y = 1LL << 64 - __builtin_clzll(x);
        return query(y - x, x) - f(f, y - x);
    };

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i64 x: a) {
        reply(f(f, x));
    }
}
