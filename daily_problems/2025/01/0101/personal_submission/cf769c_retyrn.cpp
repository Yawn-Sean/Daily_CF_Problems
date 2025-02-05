int n, m, k;
// DLRU
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
const string ss = "DLRU";

void bfs(vector<vector<int>>& dis, const vector<string>& g, int x0, int y0) {
    queue<pii> q;
    dis[x0][y0] = 0;
    q.emplace(x0, y0);
    while (!em(q)) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 or ny < 0 or nx >= n or ny >= m or g[nx][ny] == '*' or dis[nx][ny] != inf) continue;
            dis[nx][ny] = dis[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    if (k & 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<string> g(n);
    cin >> g;
    int x0 = 0, y0 = 0;
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == 'X') x0 = i, y0 = j;
        }
    }
    
    vector<vector<int>> dis(n, vector<int>(m, inf));
    bfs(dis, g, x0, y0);
    
    string path;
    
    auto dfs = [&](auto&& self, int x, int y, int step) -> bool {
        if (step == k) {
            if (x == x0 and y == y0) {
                return true;
            }
            return false;
        }
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 or ny < 0 or nx >= n or ny >= m or g[nx][ny] == '*') continue;
            if (step + 1 + dis[nx][ny] > k) continue;
            path.push_back(ss[i]);
            if (self(self, nx, ny, step + 1)) return true;
            path.pop_back();
        }
        return false;
    };
    
    dfs(dfs, x0, y0, 0);
    if (em(path)) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << path << endl;
}