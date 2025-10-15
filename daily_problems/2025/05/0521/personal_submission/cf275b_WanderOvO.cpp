/*
每个点拆成 2 个点，(x, y, dir)，其中 dir 表示自己的朝向是左右还是上下
对于每个黑色点 (x, y)，拆成 (x, y, 0) 和 (x, y, 1)，分别跑最短路，求出和他一个连通块内所有点的距离
0 变 1 需要距离 + 1，所以不能有点的距离 > 1，这个距离需要综合两个单源最短路的结果去看
*/

struct Node {
    int x, y, dir;
};

int d[2][M][M][2], n, m, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
string grid[M];

void calc(int sx, int sy, int sdir, int d[][M][2]) {
    deque<Node> dq;
    bool vis[M][M][2];
    memset(vis, 0, sizeof vis);
    vis[sx][sy][sdir] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                d[i][j][k] = INF;
            }
        }
    }
    d[sx][sy][sdir] = 0;
    dq.push_back({sx, sy, sdir});
    while (!dq.empty()) {
        auto front = dq.front();
        dq.pop_front();
        int x = front.x, y = front.y, dir = front.dir;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && grid[nx][ny] == 'B') {
                if (dir == 0) {
                    if (nx == x) {
                        if (!vis[nx][ny][dir]) {
                            vis[nx][ny][dir] = true;
                            d[nx][ny][dir] = d[x][y][dir];
                            dq.push_front({nx, ny, dir});
                        }
                    } else {
                        if (!vis[nx][ny][dir ^ 1]) {
                            vis[nx][ny][dir ^ 1] = true;
                            d[nx][ny][dir ^ 1] = d[x][y][dir] + 1;
                            dq.push_back({nx, ny, dir ^ 1});
                        }
                    }
                } else {
                    if (ny == y) {
                        if (!vis[nx][ny][dir]) {
                            vis[nx][ny][dir] = true;
                            d[nx][ny][dir] = d[x][y][dir];
                            dq.push_front({nx, ny, dir});
                        }
                    } else {
                        if (!vis[nx][ny][dir ^ 1]) {
                            vis[nx][ny][dir ^ 1] = true;
                            d[nx][ny][dir ^ 1] = d[x][y][dir] + 1;
                            dq.push_back({nx, ny, dir ^ 1});
                        }
                    }
                }
            }
        }
    }
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'B') {
                calc(i, j, 0, d[0]);
                calc(i, j, 1, d[1]);
                int max_dist = 0;
                for (int k = 1; k <= n; k++) {
                    for (int l = 1; l <= m; l++) {
                        if (grid[k][l] == 'B') {
                            max_dist = max({
                                max_dist,
                                min({
                                    d[0][k][l][0],
                                    d[0][k][l][1],
                                    d[1][k][l][0],
                                    d[1][k][l][1]
                                })
                            });
                        }
                    }
                }
                if (max_dist > 1) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
}  
