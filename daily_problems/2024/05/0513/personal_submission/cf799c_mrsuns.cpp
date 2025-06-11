void Solve() {
    int n, c, d;cin >> n >> c >> d;
    vector<array<int, 2>> jb(1), zs(1);
    for (int i = 1;i <= n;i++) {
        int val, cost;char op;cin >> val >> cost >> op;
        if (op == 'C') {
            jb.push_back({ cost,val });
        }
        else {
            zs.push_back({ cost,val });
        }
    }

    auto suan1 = [&](vector<array<int, 2>>& a, int zong) {
        sort(a.begin() + 1, a.end());
        int res = -inf;
        for (int i = 1;i < a.size();i++) {
            if (zong >= a[i][0]) {
                res = max(res, a[i][1]);
            }
        }
        return res;
        };
    auto suan = [&](vector<array<int, 2>>& a, int zong) {
        int n = a.size() - 1;
        int res = -inf;
        vector<int> mx(n + 1);for (int i = 1;i <= n;i++) {
            mx[i] = max(mx[i - 1], a[i][1]);
        }
        for (int i = 1;i <= n;i++) {
            auto ptr = partition_point(a.begin() + 1, a.begin() + i, [&](auto u) {
                return !(u[0] + a[i][0] > zong);
                }) - 1 - a.begin();
            if (ptr) res = max(res, a[i][1] + mx[ptr]);
        }
        return res;
        };
    int res = 0;
    res = max(res, suan1(jb, c) + suan1(zs, d));
    res = max(res, suan(zs, d));
    res = max(res, suan(jb, c));
    cout << res << endl;

}
