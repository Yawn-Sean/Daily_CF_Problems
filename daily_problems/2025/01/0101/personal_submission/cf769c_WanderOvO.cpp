/*
从字典序的角度，D L R U 逐渐变大，所以选择走的顺序是下左右上
长度为 k 能走回来，所以 k 必须是偶数
可以多次访问同一个位置，所以只要 X 最开始没被包围且是偶数，就一定有合法方案
按照 D/L/R/U 的顺序去看行不行
什么叫行？意思是这个位置是空的能走，且走了之后剩下的步数还足够走回去
*/

int n, m, k;
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};
int d[M][M];
bool vis[M][M];

void meibao() {
    cin >> n >> m >> k;
    vector<string> grid(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }
    int sx, sy;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }

    queue<PII> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int x = u.x, y = u.y;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx > 0 && xx <= n && yy > 0 && yy <= m && grid[xx][yy] == '.' && !vis[xx][yy]) {
                vis[xx][yy] = true;
                d[xx][yy] = d[x][y] + 1;
                q.push({xx, yy});                
            }
        }
    }

    bool ok = false;
    for (int i = 0; i < 4; i++) {
        int x = sx + dx[i], y = sy + dy[i];
        if (x > 0 && x <= n && y > 0 && y <= m && grid[x][y] == '.') {
            ok = true;
        }
    }
    char op[4] = {'D', 'L', 'R', 'U'};
    if (ok && (k % 2 == 0)) {
        int curx = sx, cury = sy;
        vector<char> res;
        for (int step = 1; step <= k; step++) {
            bool ok = false;
            for (int i = 0; i < 4; i++) {
                int x = curx + dx[i], y = cury + dy[i];
                if (x > 0 && x <= n && y > 0 && y <= m && grid[x][y] != '*' && d[x][y] <= k - step) {
                    curx = x;
                    cury = y;
                    ok = true;
                    res.push_back(op[i]);
                    break;                   
                }
            }
        }


        for (auto ch : res) {
            cout << ch;
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
