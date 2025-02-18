void solve() {
    int n, k;
    cin >> n >> k;

    vec<pair<int, int>> ans;
    for (int i = 1; i <= k; i++) {
        for (int j = i + 1; j <= k; j++) {
            if (ans.empty()) {
                ans.push_back({i, j});
                ans.push_back({j, i});
            } else {
                auto [x, y] = ans.back();
                if (x == i || y == j) {
                    ans.push_back({j, i});
                    ans.push_back({i, j});
                } else {
                    ans.push_back({i, j});
                    ans.push_back({j, i});
                }
            }
            if (ans.size() > n) break;
        }
        if (ans.size() > n) break;
    }

    if (ans.size() < n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}
