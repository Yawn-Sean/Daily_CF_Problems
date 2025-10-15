int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
    // 每个大小为x的连通块可以做到x-1个红色
    // 按照dfs的顺序依次 进去建蓝色 出去的时候拆了建红色
    cin >> n >> m;
    vector<string> g(n);
    cin >> g;
    vector<string> res;
    vector<vector<int>> st(n, vector<int>(m, false));
    
    auto dfs = [&](auto&& self, int x, int y) -> void {
        st[x][y] = true;
        res.emplace_back("B " + to_string(x + 1) + " " + to_string(y + 1));
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 or ny < 0 or nx >= n or ny >= m or st[nx][ny] or g[nx][ny] == '#') continue;
            self(self, nx, ny);
        }
        res.emplace_back("D " + to_string(x + 1) + " " + to_string(y + 1));
        res.emplace_back("R " + to_string(x + 1) + " " + to_string(y + 1));
    };
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == '#' or st[i][j]) continue;
            dfs(dfs, i, j);
            res.pop_back();
            res.pop_back();
        }
    }
    cout << sz(res) << endl;
    for (auto& s : res) {
        cout << s << endl;
    }
}