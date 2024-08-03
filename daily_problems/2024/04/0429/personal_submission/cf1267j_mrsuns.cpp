void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vector<int> cnt(n + 1);for (int i = 1;i <= n;i++) cnt[a[i]] += 1;
    int mn = n;
    for (int i = 1;i <= n;i++) {
        if (cnt[i]) mn = min(mn, cnt[i]);
    }
    vector<int> v;
    for (int i = 1;i <= n;i++) {
        if (cnt[i]) {
            v.push_back(cnt[i]);
        }
    }
    int res = n;
    for (int i = 2;i <= mn + 1;i++) {
        auto check = [&]()->ll {
            int cnt = 0;
            for (auto j : v) {
                int p = (j + i - 1) / i;
                if ((i - 1) * p <= j) cnt += p;
                else return -1;
            }
            return cnt;
            };
        int t = check();
        if (t != -1) res = min(t, res);
    }
    cout << res << endl;
}
