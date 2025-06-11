/*
使用并查集合并块
然后枚举 *，把 * 和左右上下的尝试合并（注意这几个方向可能本来也属于同一个块，要排除掉）
*/

int n, m, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
string grid[N];
int fa[N * N], sz[N * N];

int find(int x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = find(fa[x]);
}

bool together(int x, int y) {
    return find(x) == find(y);
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    fa[fx] = fy;
    sz[fy] += sz[fx];
}
 
void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fa[(i - 1) * m + j - 1] = (i - 1) * m + j - 1;
            if (grid[i][j] == '.')
                sz[(i - 1) * m + j - 1] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] != '.') continue;
            for (int k = 0; k < 4; k++) {
                int x = dx[k] + i, y = dy[k] + j;
                if (x > 0 && x <= n && y > 0 && y <= m && grid[x][y] == '.') {
                    int id1 = (i - 1) * m + j - 1, id2 = (x - 1) * m + y - 1;
                    if (!together(id1, id2)) {
                        merge(id1, id2);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '.') {
                cout << ".";
            } else {
                int res = 1;
                for (int k = 0; k < 4; k++) {
                    int x = dx[k] + i, y = dy[k] + j;
                    if (x > 0 && x <= n && y > 0 && y <= m && grid[x][y] == '.') {
                        int id1 = (i - 1) * m + j - 1, id2 = (x - 1) * m + y - 1;
                        if (!together(id1, id2)) {
                            bool ok = true;
                            for (int l = 0; l < k; l++) {
                                int xx = dx[l] + i, yy = dy[l] + j;
                                if (xx > 0 && xx <= n && yy > 0 && yy <= m && grid[xx][yy] == '.') {
                                    int id3 = (xx - 1) * m + yy - 1;
                                    if (together(id2, id3)) {
                                        ok = false;
                                    }
                                }
                            }
                            if (ok) {
                                res += sz[find(id2)];
                            }
                        }
                    }
                }
                cout << res % 10;
            }
        }
        cout << "\n";
    }
}   
