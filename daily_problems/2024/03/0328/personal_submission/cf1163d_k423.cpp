// https://codeforces.com/contest/1163/submission/253566971

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    string p, s, t;
    cin >> p >> s >> t;
    int n = s.size(), m = t.size(), inf = 1e9;
    auto init_next = [&](string &s) {
        int sz = s.size();
        vector<int> pi(sz);
        for (int i = 1, j = 0; i < sz; ++i) {
            while (j && s[i] != s[j]) j = pi[j - 1];
            pi[i] = j += s[i] == s[j];
        }
        vector<vector<int>> nxt(sz + 1, vector<int>(26));
        for (int i = 0; i <= sz; ++i) {
            for (int x = 0; x < 26; ++x) {
                int j = i;
                while (j && (j == sz || s[j] != 'a' + x)) j = pi[j - 1];
                nxt[i][x] = j + (s[j] == 'a' + x);
            }
        }
        return nxt;
    };

    vector next_s = init_next(s), next_t = init_next(t);
    vector f(n + 1, vector<int>(m + 1, -inf));
    f[0][0] = 0;
    for (char x: p) {
        char l = x == '*' ? 'a' : x, r = x == '*' ? 'z' : x;
        vector h(n + 1, vector<int>(m + 1, -inf));
        for (x = l; x <= r; ++x) {
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= m; ++j) {
                    int ii = next_s[i][x - 'a'], jj = next_t[j][x - 'a'];
                    chmax(h[ii][jj], f[i][j] + (ii == n) - (jj == m));
                }
            }
        }
        f.swap(h);
    }
    int ans = -inf;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            chmax(ans, f[i][j]);
        }
    }
    cout << ans << endl;
}
