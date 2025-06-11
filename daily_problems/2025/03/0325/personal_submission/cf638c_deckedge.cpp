const int MAXN = 2e5 + 5;
ve<pi> adj[MAXN];
ve<int> res[MAXN];
int mx = 0;

inline int read() {
    int x;
    cin >> x;
    return x;
}

void dfs(int u, int par, int nowDay) {
    int curDay = 0;
    for (auto [v, t] : adj[u]) {
        if (v == par) {
            continue;
        }
        if (curDay == nowDay) {
            curDay++;
        }
        res[curDay].emplace_back(t);
        mx = max(mx, curDay);
        dfs(v, u, curDay);
        curDay++;
    }
}

void solve() {
    int n = read();
    rep(i, 0, n - 1) {
        int u = read(), v = read();
        u--, v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    dfs(0, -1, -1);
    cout << mx + 1 << '\n';
    rep(i, 0, mx + 1) {
        cout << res[i].size() << ' ';
        for (int x : res[i]) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}

