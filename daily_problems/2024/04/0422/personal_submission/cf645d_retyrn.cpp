int n, m;
vector<vector<pii>> g;
vector<pii> E;

bool check(int len) {
    // 只使用小于len的边 看是否存在拓扑序
    vector<int> d(n, 0);
    vector<int> st(n, false);
    for (int i = 0; i < len; i ++) {
        auto [x, y] = E[i];
        d[y] += 1;
    }
    queue<int> q;
    for (int i = 0; i < n; i ++) {
        if (!d[i]) q.push(i), st[i] = true;
    }
    while (!em(q)) {
        if (sz(q) > 1) return false;
        auto t = q.front();
        q.pop();
        for (auto [x, id] : g[t]) {
            if (id < len and --d[x] == 0) {
                q.push(x);
                st[x] = true;
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        if (!st[i]) return false;
    }
    return true;
}
 
void solve() {
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].pbk({y, i});
        E.push_back({x, y});
    }
    
    if (!check(m)) {
        cout << -1 << endl;
        return;
    }
    int l = 1, r = m;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}