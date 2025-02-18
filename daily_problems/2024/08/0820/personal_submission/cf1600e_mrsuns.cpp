void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    vector<int> pre(n + 1), suf(n + 1);
    for (int i = n;i >= 1;i--) {
        if (i == n) pre[i] = 1;
        else {
            pre[i] = pre[i + 1];
            if (a[i] < a[i + 1]) pre[i]++;
            else pre[i] = 1;
        }
    }
    for (int i = 1;i <= n;i++) {
        if (i == 1) suf[i] = 1;
        else {
            suf[i] = suf[i - 1];
            if (a[i - 1] > a[i]) suf[i]++;
            else suf[i] = 1;
        }
    }
    auto dfs = [&](auto&& dfs, int l, int r)->int {
        if (l > r) return 0;
        if (l == r) return 1;
        if (a[l] >= a[r]) {
            if (pre[l] % 2 == 1) return 1;
        }
        if (a[l] <= a[r]) {
            if (suf[r] % 2 == 1) return 1;
        }
        int res = 1;
        if (a[l] < a[r]) {
            if (a[l] < a[l + 1]) res = min(res, dfs(dfs, l + 1, r));
            else return 1;
        }
        if (a[l] > a[r]) {
            if (a[r - 1] > a[r]) res = min(res, dfs(dfs, l, r - 1));
            else return 1;
        }
        return 1 - res;
        };
    cout << (dfs(dfs, 1, n) ? "Alice\n" : "Bob\n");
}
