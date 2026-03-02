void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> used(n), vis(n);
    vector<pair<int, int>> res;
    for (int k = n - 1; k >= 1; k--) {
        fill(vis.begin(), vis.end(), -1);
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            int r = a[i] % k;
            if (vis[r] != -1) {
                res.push_back({vis[r], i});
                used[i] = 1;
                break;
            }
            vis[r] = i;
        }
    }
    cout << "YES\n1\n";
    for (auto &[x, y] : res | views::reverse) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
}
