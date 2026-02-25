void solve() {
    int a, b, m;
    cin >> a >> b >> m;
    int j = 31 - __builtin_clz(m);
    int res = ((b + 1) >> j) - (a >> j);
    cout << res << '\n';
}
