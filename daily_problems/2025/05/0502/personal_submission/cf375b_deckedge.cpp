void solve() {
    int n = read(), m = read();
    vector a(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = m - 1; j >= 0; j--) {
            if (s[j] == '1') {
                a[i][j] = a[i][j + 1] + 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    int res = 0;
    for (int col = 0; col < m; col++) {
        vector<int> t(n);
        for (int row = 0; row < n; row++) {
            t[row] = a[row][col];
        }
        int mx = *max_element(all(t));
        vector<int> cnt(mx + 1, 0);
        for (int val : t) {
            cnt[val]++;
        }
        vector<int> records;
        for (int v = mx; v >= 0; v--) {
            for (int k = 0; k < cnt[v]; k++) {
                records.emplace_back(v);
            }
        }
        for (int k = 0; k < records.size(); k++) {
            int val = records[k] * (k + 1);
            res = max(res, val);
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}