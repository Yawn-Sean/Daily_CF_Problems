int p[N], sz[N];
int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}
int merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return 0;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    p[v] = u;
    return 1;
}

void Solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 1));
    for (int i = 1;i <= m;i++) {
        int u, v;cin >> u >> v;
        g[u][v] = g[v][u] = 0;
    }
    for (int i = 1;i <= n;i++) p[i] = i, sz[i] = 1;
    vector<int> col(n + 1);
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            if (g[i][j]) {
                if (!merge(i, j)) {
                    assert(col[j]);
                    if (!col[i]) col[i] = 4 - col[j];
                    if (col[i] == col[j]) return cout << "No" << endl, void();
                }
                else {
                    if (!col[i]) {
                        if (!col[j]) col[i] = 1;
                        else col[i] = 4 - col[j];
                    }
                    col[j] = 4 - col[i];
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        if (col[i] && p[i] == i && sz[i] > 1) cnt++;
    }
    if (cnt > 1) return cout << "No" << endl, void();
    string s;
    for (int i = 1;i <= n;i++) {
        if (col[i] == 0) col[i] = 2;
        s += char('a' + col[i] - 1);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            if (g[i][j] == 0) {
                if (abs(s[i - 1] - s[j - 1]) <= 1) continue;
                return cout << "No" << endl, void();
            }
        }
    }
    cout << "Yes" << endl;cout << s << endl;
}
