int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
    cin >> n >> m;
    vector<string> a(n);
    cin >> a;
    
    vector<vector<int>> g(n * m);
    vector<int> d(n * m);
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (a[i][j] == '*') continue;
            for (int k = 0; k < 4; k ++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx >= 0 and nx < n and ny >= 0 and ny < m and a[nx][ny] == '.') {
                    g[i * m + j].push_back(nx * m + ny);
                    d[i * m + j] += 1;
                }
            }
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int u = i * m + j;
            if (d[u] == 1) {
                q.push(u);
            }
        }
    }
    
    while (!em(q)) {
        auto u = q.front();
        q.pop();
        int x = u / m, y = u % m;
        if (a[x][y] != '.') continue;
        for (auto v : g[u]) {
            if (d[v] == 0) continue;
            int xx = v / m, yy = v % m;
            if (a[xx][yy] != '.') continue;
            d[u] -= 1;
            d[v] -= 1;
            if (x == xx) {
                if (y == yy - 1) a[x][y] = '<', a[xx][yy] = '>';
                else a[xx][yy] = '<', a[x][y] = '>';
            }
            else {
                if (x == xx - 1) a[x][y] = '^', a[xx][yy] = 'v';
                else a[xx][yy] = '^', a[x][y] = 'v';
            }
            // v被占据了 那么v相邻的点都d-1
            for (int k = 0; k < 4; k ++) {
                int nx = xx + dx[k], ny = yy + dy[k];
                if (nx >= 0 and nx < n and ny >= 0 and ny < m and a[nx][ny] == '.') {
                    int nv = nx * m + ny;
                    if (-- d[nv] == 1) {
                        q.push(nv);
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (a[i][j] == '.') {
                cout << "Not unique" << endl;
                return;
            }
        }
    }
    
    for (auto& ss : a) {
        cout << ss << endl;
    }
    
}