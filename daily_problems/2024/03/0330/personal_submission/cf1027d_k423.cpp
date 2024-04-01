// https://codeforces.com/contest/1027/submission/254062436

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> c(n), a(n), deg(n);
    for (int &x: c) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i], a[i]--;
        deg[a[i]]++;
    }
    queue<int> Q;
    vector<int> vis(n);
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            vis[i] = 1;
            Q.emplace(i);
        }
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (!--deg[a[u]]) {
            vis[a[u]] = 1;
            Q.emplace(a[u]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            int j = i, cur = c[j];
            while (!vis[j]) {
                cur = min(cur, c[j]);
                vis[j] = 1;
                j = a[j];
            }
            ans += cur;
        }
    }
    cout << ans << endl;
}
