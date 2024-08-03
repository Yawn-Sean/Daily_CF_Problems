void Solve() {
    int n, m, k, s;cin >> n >> m >> k >> s;
    vector<vector<int>> a(2, vector<int>(n + 1));
    for (int i = 1;i <= n;i++) cin >> a[0][i];
    for (int i = 1;i <= n;i++) cin >> a[1][i];

    vector<vector<array<int, 2>>> b(2, vector<array<int, 2>>(1));
    for (int i = 1;i <= m;i++) {
        int op, co;cin >> op >> co;
        op--;
        b[op].push_back({ co ,i });
    }
    sort(b[0].begin() + 1, b[0].end());
    sort(b[1].begin() + 1, b[1].end());
    auto check = [&](int x)->array<int, 3> {
        array<int, 2> mn = { inf,inf };
        for (int j = 0;j <= 1;j++) {
            for (int i = 1;i <= x;i++) {
                mn[j] = min(mn[j], a[j][i]);
            }
        }
        int now = 0;
        array<int, 2> ptr = { 1,1 };
        for (int i = 1;i <= k;i++) {
            if (ptr[0] >= b[0].size()) ptr[1]++;
            else if (ptr[1] >= b[1].size()) ptr[0]++;
            else if (b[0][ptr[0]][0] * mn[0] < b[1][ptr[1]][0] * mn[1]) ptr[0]++;
            else ptr[1]++;
        }
        for (int j = 0;j <= 1;j++) {
            for (int i = 1;i < ptr[j];i++) now += b[j][i][0] * mn[j];
        }
        //cout << now << endl;
        return { now <= s,ptr[0],ptr[1] };
    };
    int l = 1, r = n;
    array<int, 2> ans = { -1,-1 };
    while (l <= r) {
        int mid = l + r >> 1;
        auto t = check(mid);
        if (t[0]) {
            r = mid - 1;
            ans = { t[1],t[2] };
        }
        else {
            l = mid + 1;
        }
    }
    if (ans[0] == -1) cout << -1 << endl;
    else {
        cout << r + 1 << endl;

        for (int j = 0;j <= 1;j++) {
            int mn = inf, now = 1;
            for (int i = 1;i <= r + 1;i++) {
                if (mn > a[j][i]) mn = a[j][i], now = i;
            }
            for (int i = 1;i < ans[j];i++) cout << b[j][i][1] << " " << now << endl;
        }
        cout << endl;
    }
}
