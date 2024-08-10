int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> e(m, vector<int>(4, 0));
    int mx = 0;
    for (int i = 0; i < m; i ++) {
        cin >> e[i][0] >> e[i][1] >> e[i][2] >> e[i][3];
        e[i][0] -= 1;
        e[i][1] -= 1;
        mx = max(mx, e[i][3]);
    }
    
    sort(all(e), [&](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    });
    
    auto check = [&](int l, int r) {
        DSU dsu(n);
        for (int i = 0; i < m; i ++) {
            if (e[i][2] <= l and r <= e[i][3]) {
                dsu.merge(e[i][0], e[i][1]);
            }
        }
        return dsu.same(0, n - 1);
    };
    
    // 枚举左端点
    int res = 0;
    for (int i = 0; i < m; i ++) {
        int st = e[i][2];
        // 二分右端点
        if (!check(st, st)) continue;
        int l = e[i][2], r = mx;
        while (l < r) {
            auto mid = (l + r + 1) >> 1;
            if (check(st, mid)) l = mid;
            else r = mid - 1;
        }
        res = max(res, l - st + 1);
    }
    if (!res) {
        cout << "Nice work, Dima!" << endl;
    }
    else {
        cout << res << endl;
    }
}