/*
每个点要考虑对其他所有点的影响，但枚举每个点作为起点做 BFS 好像计算量太大了
注意到影响每次减半，所以事实上每个点至多往外扩展 20 层，所以以每个起点做 BFS 应该是可以的
*/

string grid[M];
int n, m, base, p, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool vis[M][M];
LL sum[M][M];

void bfs(int sx, int sy) {
    memset(vis, 0, sizeof vis);
    vis[sx][sy] = true;
    queue<PIII> q;
    int init_w = base * (grid[sx][sy] - 'A' + 1);
    q.push(mp(mp(sx, sy), init_w));
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        int x = u.x.x, y = u.x.y, w = u.y;
        sum[x][y] += w;
        for (int i = 0; i < 4; i++) {
            int xx = dx[i] + x, yy = dy[i] + y;
            if (xx > 0 && xx <= n && yy > 0 && yy <= m && grid[xx][yy] != '*' && !vis[xx][yy]) {
                vis[xx][yy] = true;
                if (w / 2 > 0) {
                    q.push(mp(mp(xx, yy), w / 2));
                }
            }
        }
    }
}

void meibao() {
    cin >> n >> m >> base >> p;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (isupper(grid[i][j])) {
                bfs(i, j);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sum[i][j] > p) {
                res++;
            }
        }
    }
    cout << res << "\n";
}
