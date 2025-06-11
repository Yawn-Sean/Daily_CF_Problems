// https://codeforces.com/contest/1575/submission/261577105

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j && t[i] != t[j]) j = pi[j - 1];
        j += t[i] == t[j];
        pi[i] = j;
    }
    vector g(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (t[i] - '0' == j) {
                g[i][j] = i + 1;
            } else {
                int k = i;
                while (k && t[k] - '0' != j) k = pi[k - 1];
                g[i][j] = k + (t[k] - '0' == j);
            }
        }
    }
    int k = n - m + 2, inf = 1e9;
    vector f(k, vector<int>(m, inf));
    f[0][0] = 0;
    for (int id = 0; id < n; ++id) {
        int x = s[id] - '0';
        vector h(k, vector<int>(m, inf));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < m; ++j) {
                if (f[i][j] > n) continue;
                for (int y = 0; y < 2; ++y) {
                    int nxt = g[j][y], inc = nxt == m;
                    if (nxt == m) nxt = pi[m - 1];
                    chmin(h[i + inc][nxt], f[i][j] + (x != y));
                }
            }
        }
        f.swap(h);
    }
    for (int i = 0; i < k; ++i) {
        int ans = ranges::min(f[i]);
        if (ans > n) ans = -1;
        cout << ans << " \n"[i == k - 1];
    }
}
