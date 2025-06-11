int n, x;

void solve() {
    cin >> n >> x;
    vector<int> a(n);
    cin >> a;
    auto [it1, it2] = minmax_element(all(a));
    int mn = *it1, mx = *it2;
    ll res = 0;
    for (int i = 0; i + 1 < n; i ++) {
        res += abs(a[i] - a[i + 1]);
    }
    if (mx >= x) {
        res += min(min(abs(a[0] - 1), abs(a[n - 1] - 1)), (mn - 1) * 2);
        cout << res << endl;
        return;
    }
    // 两个在两端
    int ans = min(abs(a[0] - 1) + abs(a[n - 1] - x), abs(a[0] - x) + abs(a[n - 1] - 1));
    // 一个在两端
    ans = min(min(abs(a[0] - 1), abs(a[n - 1] - 1)) + (x - mx) * 2, ans);
    ans = min(min(abs(a[0] - x), abs(a[n - 1] - x)) + (mn - 1) * 2, ans);
    // 都不在两端
    ans = min(ans, (x - mx) * 2 + (mn - 1) * 2);
    res += ans;
    cout << res << endl;
}