int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    
    int res = 0, need1 = 0;
    // 枚举第一个k段的首位
    for (int i = 0; i < k and i < n; i ++) {
        int need2 = 0;
        for (int j = i + k - 1; j < n; j += k) {
            need2 += a[j];
            if (need1 + need2 <= m) {
                res = max(res, j + 1);
            }
        }
        need1 += a[i];
        if (need1 <= m) res = max(res, i + 1);
    }
    cout << res << endl;
}