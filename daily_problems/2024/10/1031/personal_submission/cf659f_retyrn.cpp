void bfs(vector<vector<int>>& g, int x0, int y0) {
    int val = g[x0][y0];
    vector<vector<int>> st(n, vector<int>(m, false));
    vector<vector<int>> res(n, vector<int>(m, 0));
    queue<pii> q;
    q.emplace(x0, y0);
    st[x0][y0] = true;
    res[x0][y0] = val;
    k -= val;
    
    while (!em(q) and k > 0) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4 and k > 0; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 or ny < 0 or nx >= n or ny >= m or st[nx][ny]) continue;
            if (g[nx][ny] >= val) {
                q.emplace(nx, ny);
                st[nx][ny] = true;
                res[nx][ny] = val;
                k -= val;
            }
        } 
    }
    
    for (auto& vec : res) {
        cout << vec << endl;
    }
}

void solve() {
    cin >> n >> m >> k;
    vector<vector<int>> g(n, vector<int>(m));
    
    vector<pii> v(n * m);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j];
            int p = i * m + j;
            v[p].fi = g[i][j], v[p].se = p;
        }
    }
    sort(all(v), greater<pii>());
    vector<int> st(n * m, false);
    DSU dsu(n * m);
    
    for (auto [val, u] : v) {
        int x = u / m, y = u % m;
        st[u] = true;
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int v = nx * m + ny;
            if (nx < 0 or ny < 0 or nx >= n or ny >= m or !st[v]) continue;
            dsu.merge(u, v);
        }
        if (k % val) continue;
        int len = dsu.size(u);
        if (len >= k / val) {
            cout << "YES" << endl;
            bfs(g, x, y);
            return;
        }
    }
    
    cout << "NO" << endl;
}