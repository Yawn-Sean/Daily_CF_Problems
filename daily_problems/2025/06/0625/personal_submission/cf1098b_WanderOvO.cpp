char ch[5] = {'A', 'T', 'G', 'C'};
int n, m, min_cost;
bool vis[5];
char c[5];

void dfs(int u, vector<string> &grid, vector<vector<char>> &res) {
    if (u == 4) {
        // 行
        int row_cost = 0;
        vector<vector<char>> cur_row(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            int c1 = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != c[(i % 2 ? 2 : 0) + j % 2]) {
                    c1++;
                }
            }
            int c2 = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != c[(i % 2 ? 2 : 0) + 1 - j % 2]) {
                    c2++;
                }
            }
            row_cost += min(c1, c2);
            if (c1 < c2) {
                for (int j = 0; j < m; j++) {
                    cur_row[i][j] = c[(i % 2 ? 2 : 0) + j % 2];
                } 
            } else {
                for (int j = 0; j < m; j++) {
                    cur_row[i][j] = c[(i % 2 ? 2 : 0) + 1 - j % 2];
                }
            }
        }

        // 列
        int col_cost = 0;
        vector<vector<char>> cur_col(n, vector<char>(m));
        for (int j = 0; j < m; j++) {
            int c1 = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] != c[(j % 2 ? 2 : 0) + i % 2]) {
                    c1++;
                }
            }
            int c2 = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] != c[(j % 2 ? 2 : 0) + 1 - i % 2]) {
                    c2++;
                }
            }
            col_cost += min(c1, c2);
            if (c1 < c2) {
                for (int i = 0; i < n; i++) {
                    cur_col[i][j] = c[(j % 2 ? 2 : 0) + i % 2];
                } 
            } else {
                for (int i = 0; i < n; i++) {
                    cur_col[i][j] = c[(j % 2 ? 2 : 0) + 1 - i % 2];
                }
            }
        }

        // for (int i = 0; i < 4; i++) {
        //     cout << c[i];
        // }
        // cout << " " << row_cost << " " << col_cost << "\n";

        if (min(row_cost, col_cost) < min_cost) {
            min_cost = min(row_cost, col_cost);
            if (row_cost > col_cost) {
                swap(cur_row, cur_col);
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res[i][j] = cur_row[i][j];
                }
            }
        }

        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!vis[i]) {
            c[u] = ch[i];
            vis[i] = true;
            dfs(u + 1, grid, res);
            vis[i] = false; 
        }
    }
}

void meibao() {
    cin >> n >> m;
    vector<string> grid(n);
    vector<vector<char>> res(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    min_cost = n * m + 1;
    dfs(0, grid, res);
    // cout << min_cost << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j];
        }
        cout << "\n";
    }
}
