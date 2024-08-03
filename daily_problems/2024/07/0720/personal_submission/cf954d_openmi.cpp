void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vc<pii> edges(m);
    vc<vc<char>> has(n, vc<char>(n));
    for (auto& [a, b]: edges) {
        cin >> a >> b;
        a--, b--;
        has[a][b] = has[b][a] = 1;
    }
    vi dis_s(n, inf<int> / 2), dis_t(n, inf<int> / 2);
    dis_s[s] = 0, dis_t[t] = 0;
    bool flag;
    rep (i, 0, n) {
        flag = false;
        for (auto& [a, b]: edges) {
            if (dis_s[a] + 1 < dis_s[b]) dis_s[b] = dis_s[a] + 1, flag = true; 
            if (dis_t[a] + 1 < dis_t[b]) dis_t[b] = dis_t[a] + 1, flag = true;
            if (dis_s[b] + 1 < dis_s[a]) dis_s[a] = dis_s[b] + 1, flag = true;         
            if (dis_t[b] + 1 < dis_t[a]) dis_t[a] = dis_t[b] + 1, flag = true;
        }
        if (!flag) break;
    }
    int ans = 0;
    rep (i, 0, n) rep (j, i + 1, n) if (!has[i][j]) {
        if (dis_s[i] + dis_t[j] + 1 >= dis_s[t] and dis_s[j] + dis_t[i] + 1 >= dis_s[t]) ans++;
    }
    cout << ans << nl;
}
