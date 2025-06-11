/*
设 d[i][j][k] 表示从起点走到 (i, j)，且所有方块被旋转了 k 次的最短时间是多少
k 只需要考虑 0 1 2 3
可以看成 4 层的分层图，下层连上层，顶层回过头来连到底层
这样实际上 (i, j, k) 才唯一确定一个点
所有边权都是 1，直接 bfs 即可，注意判重复
d[sx][sy][0] = 0
对于 d[i][j][k]，能转移到什么地方？
- 跨层转移：d[i][j][(k + 1) % 4] = min(d[i][j][(k + 1) % 4], d[i][j][k] + 1)
- 同层转移：d[xx][yy][k] = min(d[xx][yy][k], d[i][j][k] + 1)，如果 (i, j) 转 k 次的情况下能走到 (xx, yy)
两个方向的门是对着的才能走！
*/

struct Point {
    int i, j, k;
};

int n, m, sx, sy, tx, ty;
// 上 左 下 右
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int ne[4] = {2, 3, 0, 1};
int door[N][N][4];
Point from[N][N][4];
string grid[N];
bool vis[N][N][4];
int d[N][N][4];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }

    cin >> sx >> sy >> tx >> ty;

    auto get_direction = [&] (string direction) -> int {
        int res = 0;
        for (int i = 0; i < direction.size(); i++) {
            if (direction[i] == '1') {
                res |= (1 << i);
            }
        }
        return res;
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            string direction = "0000";
            if (grid[i][j] == '+') {
                direction = "1111";
            } else if (grid[i][j] == '-') {
                direction = "0101";
            } else if (grid[i][j] == '|') {
                direction = "1010";
            } else if (grid[i][j] == '^') {
                direction = "1000";
            } else if (grid[i][j] == '>') {
                direction = "0100";
            } else if (grid[i][j] == 'v') {
                direction = "0010";
            } else if (grid[i][j] == '<') {
                direction = "0001";
            } else if (grid[i][j] == 'L') {
                direction = "1110";
            } else if (grid[i][j] == 'R') {
                direction = "1011";
            } else if (grid[i][j] == 'U') {
                direction = "0111";
            } else if (grid[i][j] == 'D') {
                direction = "1101";
            }
            door[i][j][0] = get_direction(direction);
            string d1 = direction[3] + direction.substr(0, 3);
            door[i][j][1] = get_direction(d1);
            string d2 = d1[3] + d1.substr(0, 3);
            door[i][j][2] = get_direction(d2);
            string d3 = d2[3] + d2.substr(0, 3);
            door[i][j][3] = get_direction(d3);
            // cout << direction << " " << d1 << " " << d2 << " " << d3 << "\n";
        }
    }

    queue<Point> q;
    q.push({sx, sy, 0});
    memset(d, 0x3f, sizeof d);
    d[sx][sy][0] = 0;
    vis[sx][sy][0] = true;

    while (!q.empty()) {
        Point u = q.front();
        q.pop();

        int i = u.i, j = u.j, k = u.k;
        // cout << i << " " << j << " " << k << " " << d[i][j][k] << "\n";
        if (i == tx && j == ty) {
            break;
        }


        d[i][j][(k + 1) % 4] = min(d[i][j][(k + 1) % 4], d[i][j][k] + 1);
        if (!vis[i][j][(k + 1) % 4]) {
            vis[i][j][(k + 1) % 4] = true;
            q.push({i, j, (k + 1) % 4});
            from[i][j][(k + 1) % 4] = {i, j, k};
        }

        int direction = door[i][j][k];
        for (int l = 0; l < 4; l++) {
            if ((direction >> l) & 1) {
                int xx = dx[l] + i, yy = dy[l] + j;
                if (xx <= 0 || xx > n || yy <= 0 || yy > m) {
                    continue;
                }
                int next_direction = door[xx][yy][k];
                if ((next_direction >> ne[l]) & 1) {
                    d[xx][yy][k] = min(d[xx][yy][k], d[i][j][k] + 1);
                    if (!vis[xx][yy][k]) {
                        vis[xx][yy][k] = true;
                        q.push({xx, yy, k});
                        from[xx][yy][k] = {i, j, k};
                    }
                }
            }
        }
    }

    int res = INF;
    for (int k = 0; k < 4; k++) {
        // cout << d[tx][ty][k] << "\n";
        res = min(res, d[tx][ty][k]);
    }
    if (res > INF / 2) {
        res = -1;
    }
    cout << res << "\n";
}   
