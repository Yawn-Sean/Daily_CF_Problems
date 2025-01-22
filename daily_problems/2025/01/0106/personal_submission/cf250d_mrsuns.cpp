void Solve() {
    int n, m, a, b;cin >> n >> m >> a >> b;
    vector<pair<ld, int>> ay(n + 1);vector<int> by(m + 1);
    for (int i = 1;i <= n;i++) {
        int x;cin >> x;
        ay[i] = { 1.0 * x,i };
    }
    for (int i = 1;i <= m;i++) {
        int x;cin >> x;
        by[i] = x;
    }
    vector<int> c(m + 1);
    for (int i = 1;i <= m;i++) {
        cin >> c[i];
    }
    sort(ay.begin() + 1, ay.end());
    auto dis = [&](ld a, ld b, ld c, ld d)->ld {
        return sqrtl((a - c) * (a - c) + (b - d) * (b - d));
        };
    ld res = 1e18;int res1 = 1, res2 = 1;
    for (int i = 1; i <= m;i++) {
        ld goa = 1. * by[i] / b * a;
        auto p = lower_bound(ay.begin() + 1, ay.end(), pair<ld, int>{goa, -1}) - ay.begin();
        if (p != n + 1) {
            ld cur = dis(0, 0, a, ay[p].first) + dis(a, ay[p].first, b, by[i]) + c[i];
            if (res > cur) {
                res = cur;
                res1 = ay[p].second, res2 = i;
            }
        }
        if (p != 1) {
            ld cur = dis(0, 0, a, ay[p - 1].first) + dis(a, ay[p - 1].first, b, by[i]) + c[i];
            if (res > cur) {
                res = cur;
                res1 = ay[p - 1].second, res2 = i;
            }
        }
    }
    //cout << setprecision(15) << res << endl;
    cout << res1 << " " << res2 << endl;
}
