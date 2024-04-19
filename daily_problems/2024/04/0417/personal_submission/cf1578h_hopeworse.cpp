void solve() {
    string s;
    cin >> s;
    auto dfs = [&](auto self, int l, int r) {
        if (l + 1 == r)return 0;
        int dep = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] == '(')dep++;
            if (s[i] == ')')dep--;
            if (dep == 0 && s[i] == '-') {
                return max(self(self, l, i - 1) + 1, self(self, i + 2, r));
            }
        }
        return self(self, l + 1, r - 1);
    };
    int ans = dfs(dfs, 0, s.size() - 1);
    cout << ans << endl;
}
