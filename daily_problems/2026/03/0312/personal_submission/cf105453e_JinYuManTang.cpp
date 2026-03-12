void solve() {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> vis(n), cost(n + 1, 1e4);
    for (int i = 0; i < n; i++) {
        cost[i] = a[i][i];
    }
    i64 res = 0;
    for (int i = 0; i < n; i++) {
        int c = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (c == -1 || cost[j] < cost[c])) {
                c = j;
            }
        }
        res += cost[c];
        vis[c] = 1;
        for (int j = 0; j < n; j++) {
            chmin(cost[j], a[c][j]);
        }
    }
    cout << res;
}
