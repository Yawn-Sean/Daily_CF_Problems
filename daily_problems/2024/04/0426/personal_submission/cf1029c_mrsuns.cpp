void Solve() {
    int n;cin >> n;
    vector<array<int, 2>> a(n + 1);
    int mx1 = 0, mx2 = 0;
    int mn1 = 1e9, mn2 = 1e9;
    for (int i = 1;i <= n;i++) {
        int x, y;cin >> x >> y;
        a[i] = { x,y };
        if (mx1 < x) mx2 = mx1, mx1 = x;
        else mx2 = max(mx2, x);

        if (mn1 > y) mn2 = mn1, mn1 = y;
        else mn2 = min(mn2, y);
    }
    int res = 0;
    for (int i = 1;i <= n;i++) {
        int x = a[i][0] == mx1 ? mx2 : mx1;
        int y = a[i][1] == mn1 ? mn2 : mn1;
        res = max(res, y - x);
    }
    cout << res << endl;

}
