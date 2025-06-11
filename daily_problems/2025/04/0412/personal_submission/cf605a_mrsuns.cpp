void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i], pos[a[i]] = i;
    int lst = 0, s = 0, res = 0;
    for (int i = 1;i <= n;i++) {
        if (pos[i] > lst) s++, lst = pos[i];
        else {
            res = max(res, s);
            lst = pos[i];
            s = 1;
        }
    }
    res = max(res, s);
    cout << n - res << endl;
}
