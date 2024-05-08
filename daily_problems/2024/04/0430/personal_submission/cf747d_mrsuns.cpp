void Solve() {
    int n;cin >> n;int k;cin >> k;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] < 0) cnt += 1;
    }
    if (cnt > k) {
        return cout << -1 << endl, void();
    }

    k -= cnt;
    int res = cnt * 2;

    int lst = 0;
    vector<int> v;
    for (int i = 1;i <= n;i++) {
        if (a[i] < 0) {
            if (lst) {
                v.push_back(i - lst - 1);
            }
            lst = i;
        }
    }
    int bak_k = k, bak_res = res;
    sort(v.begin(), v.end());
    for (auto i : v) {
        if (k >= i) {
            k -= i, res -= 2;
        }
        else break;
    }
    int ans = res;

    k = bak_k, res = bak_res;
    if (lst && k >= n - lst) {
        k -= n - lst;
        res -= 1;
        for (auto i : v) {
            if (k >= i) {
                k -= i, res -= 2;
            }
            else break;
        }
        ans = min(res, ans);
    }

    cout << ans << endl;

}
