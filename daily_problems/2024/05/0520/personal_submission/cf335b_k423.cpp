// https://codeforces.com/contest/335/submission/261744414

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    string s;
    cin >> s;
    vector<int> cnt('z' + 1);
    for (char x: s) cnt[x]++;
    for (char x: s) {
        if (cnt[x] >= 100) {
            cout << string(100, x) << endl;
            return;
        }
    }
    int n = s.size();
    vector<array<int, 26>> f1(n), f2(n);
    array<int, 26> pre, nxt;
    pre.fill(-1), nxt.fill(n);
    for (int i = 0, j = n - 1; i < n; ++i, --j) {
        f1[i] = pre, f2[j] = nxt;
        pre[s[i] - 'a'] = i, nxt[s[j] - 'a'] = j;
    }
    vector f(n, vector<int>(n));
    vector p(n, vector<pair<int, int>>(n, {-1, n}));
    int mx = 1, L = 0, R = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= i; --j) {
            if (s[i] != s[j]) continue;
            for (int x = 0; x < 26; ++x) {
                int l = f1[i][x], r = f2[j][x];
                if (l >= 0 && r < n && f[l][r] > f[i][j]) {
                    f[i][j] = f[l][r];
                    p[i][j] = {l, r};
                }
            }
            f[i][j] += 1 + (i < j);
            if (f[i][j] <= 100 && f[i][j] > mx) {
                mx = f[i][j], L = i, R = j;
            }
        }
    }
    string ans;
    for (int i = L, j = R; i >= 0; tie(i, j) = p[i][j]) {
        ans += s[i];
    }
    cout << string(ans.rbegin(), ans.rend()) << ans.substr(L == R) << endl;
}
