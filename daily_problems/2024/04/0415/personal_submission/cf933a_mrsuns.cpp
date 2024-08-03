void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vector<array<int, 4>> f(n + 1);//1..2..1..2，dp表示到第几段的最大值
    for (int i = 1;i <= n;i++) {
        f[i][0] = f[i - 1][0] + (a[i] == 1);
        f[i][1] = max(f[i - 1][1], f[i - 1][0]) + (a[i] == 2);
        f[i][2] = max(f[i - 1][2], f[i - 1][1]) + (a[i] == 1);
        f[i][3] = max(f[i - 1][3], f[i - 1][2]) + (a[i] == 2);
    }
    cout << *max_element(f[n].begin(), f[n].end()) << endl;
}
