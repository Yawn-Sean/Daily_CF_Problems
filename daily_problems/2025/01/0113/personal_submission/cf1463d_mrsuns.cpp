void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vector<int> v(2 * n + 1);for (int i = 1;i <= n;i++) v[a[i]]++;
    vector<int> b(1);
    for (int i = 1;i <= 2 * n;i++) {
        if (v[i] == 0) b.push_back(i);
    }
    auto ck1 = [&](int x) {
        if (x == 0) return 1;
        for (int i = 1;i <= x;i++) {
            if (a[i] < b[n - x + i]);
            else return 0;
        }
        return 1;
        };
    auto ck2 = [&](int x) {
        if (x == n) return 1;
        for (int i = 1;i + x <= n;i++) {
            if (a[i + x] > b[i]);
            else return 0;
        }
        return 1;
        };

    int L, R;
    {
        int l = 0, r = n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (ck1(mid)) l = mid + 1;
            else r = mid - 1;
        }
        R = r;
    };

    {
        int l = 0, r = n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (ck2(mid)) r = mid - 1;
            else l = mid + 1;
        }
        L = l;
    };
    cout << R - L + 1 << endl;
}
