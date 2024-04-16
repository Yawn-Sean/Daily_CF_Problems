// https://codeforces.com/contest/623/submission/256893309

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, m;
    cin >> n >> m;
    string s(n, '.');
    vector<vector<int>> adj(n, vector<int>(n));
    vector<int> deg(n);
    while (m--) {
        int i, j;
        cin >> i >> j, --i, --j;
        if (i > j) swap(i, j);
        ++deg[i], ++deg[j];
        adj[i][j] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (deg[i] == n - 1) {
            s[i] = 'b';
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != '.') continue;
        s[i] = 'a';
        for (int j = i + 1; j < n; ++j) {
            if (s[j] != '.') continue;
            if (adj[i][j]) s[j] = 'a';
            else s[j] = 'c';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adj[i][j] != abs(s[i] - s[j]) <= 1) {
                return NO();
            }
        }
    }
    YES();
    cout << s << endl;
}
