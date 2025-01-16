void Solve() {
    int n, k;cin >> n >> k;
    vector<int> a(n + 1); for (int i = 1;i <= n;i++) cin >> a[i];
    vector<int> s(n + 1);
    for (int i = 1;i <= n;i++)
        s[i] = s[i - 1] + a[i];
    sort(s.begin() + 1, s.end());
    vector<int> b(k + 1);for (int i = 1;i <= k;i++) cin >> b[i];
    sort(b.begin() + 1, b.end());
    set<int> st;
    for (int i = 1;i <= n;i++) {
        int j, p = i + 1, lp = i;
        for (j = 1;j < k and p <= n;p++) {
            if (b[j + 1] - b[j] == s[p] - s[lp]) {
                lp = p;
                j++;
            }
        }
        if (j == k) {
            st.insert(s[i]);
        }
    }
    cout << st.size() << endl;
}
