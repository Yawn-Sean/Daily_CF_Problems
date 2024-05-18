void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int res = 1;
    for (int i = 2;i <= n;i++) {
        int d = abs(a[i] - a[i - 1]);
        if (d == 1) continue;
        if (res == 1) res = d;
        else if (res != d) {
            return cout << "NO" << endl, void();
        }
    }
    if (res == 0) return cout << "NO" << endl, void();
    auto calc = [&](int id)->array<int, 2> {
        int x = (id + res - 1) / res;
        return { x , id - (x - 1) * res };
    };
    array<int, 2> lst = calc(a[1]);
    for (int i = 2;i <= n;i++) {
        auto now = calc(a[i]);
        if (abs(now[0] - lst[0]) + abs(now[1] - lst[1]) != 1) return cout << "NO" << endl, void();
        lst = now;
    }
    cout << "YES" << endl;
    cout << (int)1e9 << " " << res << endl;

}
