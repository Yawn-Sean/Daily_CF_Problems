void Solve() {
    string s;cin >> s;
    int n = s.size();s = ' ' + s;
    vector<ll> f(27);
    auto check = [&](int x) {
        ll res = 0;
        vector<int> cnt(27);int zaicnt = 0;
        for (int l = 1, r = 1;r <= n;r++) {
            int u = s[r] - 'a';
            if (!cnt[u]) zaicnt++;
            cnt[u]++;
            while (zaicnt > x) {
                int v = s[l] - 'a';
                if (--cnt[v] == 0) zaicnt--;
                l++;
            }
            if (zaicnt <= x) {
                res += r - l + 1;
            }
        }
        return res;
        };
    unordered_set<int> st;for (int i = 1;i <= n;i++) st.insert(s[i] - 'a');
    int many = st.size();
    for (int i = 1;i <= many;i++) {
        f[i] = check(i);
    }
    cout << many << endl;
    for (int i = 1;i <= many;i++) {
        cout << f[i] - f[i - 1] << endl;
    }
}
