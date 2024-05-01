void Solve() {
    int n;cin >> n;
    vector<int> a(n + 2);for (int i = 1;i <= n;i++) cin >> a[i];
    auto check = [&](int x) {
        vector<int> dif(n + 2);
        for (int i = 0;i <= n + 1;i++) {
            if (x < a[i]) continue;
            int d = x - a[i] + 1;
            int l = i - d + 1, r = i + d - 1;
            l = max(l, 1ll), r = min(n, r);
            dif[l] += 1, dif[r + 1] -= 1;
        }
        for (int i = 1;i <= n;i++) dif[i] += dif[i - 1];
        for (int i = 1;i <= n;i++) {
            if (!dif[i]) return 0;
        }
        return 1;
        };
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << r + 1 << endl;

}
