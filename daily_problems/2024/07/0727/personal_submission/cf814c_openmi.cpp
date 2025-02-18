// O(n^2 + q) 108ms
void solve() {
    int n;
    cin >> n;
    string s; 
    cin >> s;
    vvc<int> vp(26);
    rep (i, 0, n) {
        vp[s[i] - 'a'].push_back(i);
    }
    vvc<int> mem(26, vi(n + 1));
    rep (i, 0, 26) {
        rb (m, 0, n) {
            int ans = m, l = 0, r = 0;
            auto& v = vp[i];
            while (r < v.size()) {
                while (l < r and v[r] - v[l] + 1 - (r - l + 1) > m) l++;
                int t = v[r] - v[l] + 1, d = v[r] - v[l] + 1 - (r - l + 1);
                ans = max(ans, min(n, t + (m - d)));
                if (ans == n) break;
                r++;
            }
            mem[i][m] = ans;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int m; char c;
        cin >> m >> c;
        if (m > n) m = n;
        cout << mem[c - 'a'][m] << nl;
    }
}
// O(nq) 3e8 578ms
void solve2() {
    int n;
    cin >> n;
    string s; 
    cin >> s;
    vvc<int> vp(26);
    rep (i, 0, n) {
        vp[s[i] - 'a'].push_back(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int m; char c;
        cin >> m >> c;
        int ans = min(m, n), l = 0, r = 0;
        auto& v = vp[c - 'a'];
        while (r < v.size()) {
            while (l < r and v[r] - v[l] + 1 - (r - l + 1) > m) l++;
            int t = v[r] - v[l] + 1, d = v[r] - v[l] + 1 - (r - l + 1);
            ans = max(ans, min(n, t + (m - d)));
            if (ans == n) break;
            r++;
        }
        cout << ans << nl;
 
    }
}
