void Solve() {
    int n;cin >> n;
    vector<array<ld, 3>> a(n + 1);
    for (int i = 0;i <= n;i++) {
        int x, y, z;cin >> x >> y >> z;
        a[i] = { 1.0 * x,1.0 * y,1.0 * z };
    }
    int v1, v2;cin >> v2 >> v1;
    array<ld, 3> p;cin >> p[0] >> p[1] >> p[2];
    auto dis = [&](array<ld, 3> u, array<ld, 3> v)->ld {
        return sqrt(
            (u[0] - v[0]) * (u[0] - v[0]) +
            (u[1] - v[1]) * (u[1] - v[1]) +
            (u[2] - v[2]) * (u[2] - v[2])
        );
        };
    ld ts = 0;
    for (int i = 1;i <= n;i++) {
        ld t1 = dis(a[i - 1], a[i]) / v1;
        ld t2 = dis(p, a[i]) / v2;
        if (t2 <= ts + t1) {
            const ld eps = 1e-10;
            ld l = 0, r = 1;
            while (r - l >= eps) {
                ld mid = (l + r) / 2;
                array<ld, 3> na = {
                    a[i - 1][0] + (a[i][0] - a[i - 1][0]) * mid,
                    a[i - 1][1] + (a[i][1] - a[i - 1][1]) * mid,
                    a[i - 1][2] + (a[i][2] - a[i - 1][2]) * mid,
                };
                auto t3 = t1 * mid;
                auto t4 = dis(na, p) / v2;
                if (t4 <= ts + t3) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            cout << "YES\n";
            ld d = (l + r) / 2;
            cout << ts + t1 * d << endl;
            cout << a[i - 1][0] + (a[i][0] - a[i - 1][0]) * d << ' ';
            cout << a[i - 1][1] + (a[i][1] - a[i - 1][1]) * d << ' ';
            cout << a[i - 1][2] + (a[i][2] - a[i - 1][2]) * d << ' ';
            cout << endl;
            return;
        }
        ts += t1;
    }
    cout << "NO\n";
}
