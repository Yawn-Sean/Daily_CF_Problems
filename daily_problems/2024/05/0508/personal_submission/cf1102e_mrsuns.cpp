void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    map<int, vector<int>> mp;
    for (int i = 1;i <= n;i++) {
        mp[a[i]].push_back(i);
    }
    vector<int> far(n + 1);for (int i = 1;i <= n;i++) far[i] = mp[a[i]].back();
    StaticTable stb(far);
    int now = 1, res = 0;
    while (now <= n) {
        int lim = far[now];
        int mx = stb.query(now, lim);
        while (mx > lim) {
            lim = mx;
            mx = stb.query(now, lim);
        }
        now = lim + 1;
        res += 1;
    }
    int da = 1;
    for (int i = 1;i <= res - 1;i++) {
        da = da * 2 % MOD;
    }
    cout << da << endl;
}
