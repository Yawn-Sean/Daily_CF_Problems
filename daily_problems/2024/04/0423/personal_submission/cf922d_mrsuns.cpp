void Solve() {
    int n;cin >> n;
    vector<array<int, 2>> a(n + 1);
    ll res = 0;
    for (int i = 1;i <= n;i++) {
        string str;cin >> str;
        int s = 0, h = 0;
        for (auto i : str) {
            if (i == 'h') {
                h += 1;
                res += s;
            }
            else {
                s += 1;
            }
        }
        a[i] = { s,h };
    }
    sort(a.begin() + 1, a.end(), [&](array<int, 2> u, array<int, 2> v) {
        return 1ll * u[0] * v[1] > 1ll * u[1] * v[0];
        });
    int s = 0;
    for (int i = 1;i <= n;i++) {
        res += 1ll * a[i][1] * s;
        s += a[i][0];
    }
    cout << res << endl;
}
