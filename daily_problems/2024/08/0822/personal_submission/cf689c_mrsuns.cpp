void Solve() {
    int m;cin >> m;
    auto ck = [&](int n) {
        int res = 0;
        for (int k = 2;k * k * k <= n;k++) {
            res += n / (k * k * k);
        }
        return res;
        };
    int l = 1, r = 1e18, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (ck(mid) >= m) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    if (ck(ans) == m) cout << ans << endl;
    else cout << "-1\n";
}
