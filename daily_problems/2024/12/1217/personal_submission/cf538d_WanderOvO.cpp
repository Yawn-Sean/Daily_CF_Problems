/*
一共 2500 个格子
并不知道移动向量到底有多少个，只知道至多有 2500 种移动向量
o 格子通过这个向量需要覆盖所有的 x 格子，也可以覆盖一些 o 格子，不能覆盖任何一个 . 格子
枚举移动向量，枚举 o 格子，对所有能走的地方做标记，最后看看走的是否合法，合法就留着这个移动向量，不合法就扬了
*/

int n;
string grid[M];
int vis[M][M];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }
    vector<PII> vecs;
    for (int dx = -n; dx <= n; dx++) {
        for (int dy = -n; dy <= n; dy++) {
            memset(vis, 0, sizeof vis);
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (grid[i][j] == 'o' && i + dx > 0 && i + dx <= n && j + dy > 0 && j + dy <= n) {
                        vis[i + dx][j + dy] = 1;
                    }
                }
            }
            bool ok = true;
            for (int i = 1; i <= n && ok; i++) {
                for (int j = 1; j <= n && ok; j++) {
                    if (grid[i][j] == '.') {
                        if (vis[i][j] == 1) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
            if (ok) {
                vecs.push_back({dx, dy});
            }
        }
    }

    memset(vis, 0, sizeof vis);
    for (auto v : vecs) {
        int dx = v.x, dy = v.y;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i][j] == 'o' && i + dx > 0 && i + dx <= n && j + dy > 0 && j + dy <= n) {
                    vis[i + dx][j + dy] = 1;
                }
            }
        }
    }

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == '.' && vis[i][j] == 1) {
                ok = false;
            }
            if (grid[i][j] == 'x' && vis[i][j] == 0) {
                ok = false;
            }
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    vector<vector<char>> res(2 * n, vector<char>(2 * n, '.'));
    for (auto v : vecs) {
        int xx = n + v.x, yy = n + v.y;
        if (xx > 0 && xx < 2 * n && yy > 0 && yy < 2 * n) {
            res[xx][yy] = 'x';
        }
    }
    res[n][n] = 'o';
    for (int i = 1; i <= 2 * n - 1; i++) {
        for (int j = 1; j <= 2 * n - 1; j++) {
            cout << res[i][j];
        }
        cout << "\n";
    }
}
