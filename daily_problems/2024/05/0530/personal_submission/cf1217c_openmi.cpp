void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> prez(n + 1);
    rep (i, 0, n) {
        if (s[i] == '0') prez[i + 1] = prez[i] + 1;
        else prez[i + 1] = 0;
    }
    int ans = 0;
    rep (r, 0, n) {
        int cur = 0;
        br (l, r, max(0, r - 18)) if (s[l] == '1'){
            cur |= 1 << r - l;
            if (cur <= r - l + 1 + prez[l]) {
                ans += 1;
            }
        }
    }
    cout << ans << nl;
}
