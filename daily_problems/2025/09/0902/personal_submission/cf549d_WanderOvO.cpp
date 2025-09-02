/*
矩阵只有 100 * 100，能否每次暴力找最右下角的
10^8 非常可以接受的样子
正确性如何证明？
倘若我们不每次找最外面的，而是先把里面的给搞了
*/

int n, m, grid[N][N], target[N][N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            target[i][j + 1] = (s[j] == 'B' ? -1 : 1);
        }
    }

    int res = 0;
    while (true) {
        int x = -1, y = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i][j] != target[i][j]) {
                    x = i;
                    y = j;
                }
            }
        }

        if (x == -1 && y == -1) {
            break;
        }

        res++;
        int d = target[x][y] - grid[x][y];
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                grid[i][j] += d;
            }
        }
    }

    cout << res << "\n";
}
