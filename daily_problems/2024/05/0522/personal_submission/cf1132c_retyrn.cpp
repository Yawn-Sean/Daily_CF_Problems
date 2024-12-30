int n, m;

void solve() {
    cin >> n >> m;
    vector<pii> a(m);
    cin >> a;
    vector<int> d(n + 2, 0);
    for (auto [l, r] : a) {
        d[l] += 1;
        d[r + 1] -= 1;
    }
    for (int i = 1; i <= n; i ++) {
        d[i] += d[i - 1];
    }
    
    // 记录哪些点只有1个或者2个人涂到
    vector<int> cnt(m, 0); // 独占
    vector<vector<int>> p(n + 2);
    for (int j = 0; j < m; j ++) {
        auto l = a[j].fi, r = a[j].se;
        for (int i = l; i <= r; i ++) {
            if (d[i] <= 2) {
                p[i].push_back(j);
                if (d[i] == 1) {
                    cnt[j] += 1;
                }
            }
        }
    }
    
    map<pii, int> mp;
    for (int i = 1; i <= n; i ++) {
        if (sz(p[i]) == 2) {
            int x = p[i][0], y = p[i][1];
            if (x > y) swap(x, y);
            mp[mpr(x, y)] += 1;
        }
    }
    
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        if (d[i] > 0) sum += 1;
    }
    
    // 枚举删除哪两个数
    int res = 0;
    for (int i = 0; i < m; i ++) {
        for (int j = i + 1; j < m; j ++) {
            int ans = sum - cnt[i] - cnt[j] - (mp.count(mpr(i, j)) ? mp[mpr(i, j)] : 0);
            res = max(res, ans);
        }
    }
    cout << res << endl;
}