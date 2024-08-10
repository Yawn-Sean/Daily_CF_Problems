/*
(i, j) 只能到达 k 步以内可以走到的地方，这个区域是一个菱形，之后只需要考虑边界的格子外扩能到哪里
玩家数量并不多，棋盘大小也不大，事实上 s <= 1e6 即可
如果暴力模拟这个过程，每个格子只会被走到 1 次
*/

int T;
int n, m, p, s[M];
string grid[N];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void bfs(vector<PII> &border, int val, int max_step) {
    for (int i = 0; i < max_step && border.size() != 0; i++) {
        vector<PII> new_border;
        for (auto &ver : border) {
            int x = ver.x, y = ver.y;
            for (int j = 0; j < 4; j++) {
                int xx = x + dx[j], yy = y + dy[j];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == '.') {
                    new_border.pb({xx, yy});
                    grid[xx][yy] = (char)(val + '0');
                }
            }
        }
        border = new_border;
    }
}

void solve1() {
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<PII> border[M];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isdigit(grid[i][j])) {
                int val = grid[i][j] - '0';
                border[val].pb({i, j});
            }
        }
    }
    while (true) {
        bool all_visited = true;
        for (int i = 1; i <= p; i++) {
            if (border[i].size() == 0) continue;
            all_visited = false;
            bfs(border[i], i, s[i]);
        }
        if (all_visited) {
            break;
        }
    }
    vector<int> res(p + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isdigit(grid[i][j])) {
                res[grid[i][j] - '0']++;
            }
        }
    }
    for (int i = 1; i <= p; i++) {
        cout << res[i] << " ";
    }
}       
