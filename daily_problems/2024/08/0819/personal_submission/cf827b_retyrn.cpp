int n, k;

void solve() {
    cin >> n >> k;
    // 1 2-k+1 k+2..n
    vector<vector<int>> a(k);
    vector<pii> res;
    for (int i = 0; i < k; i ++) {
        a[i].push_back(i + 2);
        res.emplace_back(1, i + 2);
    }
    int idx = 0;
    for (int i = k + 2; i <= n; i ++) {
        res.emplace_back(a[idx].back(), i);
        a[idx].push_back(i);
        idx = (idx + 1) % k;
    }
    cout << (sz(a[0]) + sz(a[1])) << endl;
    cout << res << endl;
}