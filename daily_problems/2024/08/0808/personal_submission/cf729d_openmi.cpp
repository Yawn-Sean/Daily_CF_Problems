void solve() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int i = 0, j;
    vector<int> ans;
    while (i < n) {
        j = i;
        while (j < n and s[j] == '0') j++;
        for (int t = i + b - 1; t < j; t += b) {
            ans.push_back(t + 1);
        }
        i = j + 1;
    }
    int m = ans.size() - a + 1;
    cout << m << nl;
    rep (i, 0, m) {
        cout << ans[i] << ' ';
    }
}
