/*
每个位置至多会攻击 8 个其他位置，可以建图
对于每个连通块，只能选不相邻的，每个连通块是不是二分图呢？
如果是的话，就可以直接染色，选较多的那一半
通过 assert 发现好像真的是二分图
*/

int n, m, color[N][N], tot_cnt, cnt1;
int dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
bool vis[N][N];

void dfs(int x, int y, int c) {
    vis[x][y] = true;
    tot_cnt++;
    cnt1 += c;
    color[x][y] = c;
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx > 0 && xx <= n && yy > 0 && yy <= m) {
            if (!vis[xx][yy]) {
                dfs(xx, yy, c ^ 1);
            } else {
                assert(color[xx][yy] != color[x][y]);
            }
        }
    }
}

void meibao() {
    cin >> n >> m;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                tot_cnt = 0;
                cnt1 = 0;
                dfs(i, j, 0);
                res += max(cnt1, tot_cnt - cnt1);
            }
        }
    }
    cout << res << "\n";
}
