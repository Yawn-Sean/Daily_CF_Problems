/*
对于每种字符，存储其出现的位置
这些位置应该要么在一行里，要么在一列里，否则肯定不行
由于必须从 a 开始搞，逐个递增，所以假如遇到有个字符没了，其可能是完全被覆盖了，也可能是根本没染色过
事实上，假如字符 ch 没出现过，其可以直接和后面某个已经出现过的字符的染色位置一样，就可以变成被覆盖了
如果在一行或者一列里，就在另一个空白的里面进行操作
最后检查是否和输入给的矩阵一模一样
*/

void meibao() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n), empty_grid;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    string empty_line = "";
    for (int i = 0; i < m; i++) {
        empty_line += ".";
    }
    for (int i = 0; i < n; i++) {
        empty_grid.push_back(empty_line);
    }

    vector<vector<PII>> pos(26);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (islower(grid[i][j])) {
                pos[grid[i][j] - 'a'].push_back({i, j});
            }
        }
    }

    vector<PII> res;
    int last_unused_ch = 0;
    for (int ch = 0; ch < 26; ch++) {
        if (pos[ch].size() > 0) {
            bool ok = true;
            int row_id = pos[ch][0].x, max_col_id = -1, min_col_id = m + 1;
            for (int i = 0; i < pos[ch].size(); i++) {
                if (row_id != pos[ch][i].x) {
                    ok = false;
                    break;
                }
                max_col_id = max(max_col_id, pos[ch][i].y);
                min_col_id = min(min_col_id, pos[ch][i].y);
            }
            if (ok) {
                while (last_unused_ch <= ch) {
                    res.push_back({row_id, min_col_id});
                    res.push_back({row_id, max_col_id});
                    last_unused_ch++;
                }
            } else {
                ok = true;
                int col_id = pos[ch][0].y, max_row_id = -1, min_row_id = n + 1;
                for (int i = 0; i < pos[ch].size(); i++) {
                    if (col_id != pos[ch][i].y) {
                        ok = false;
                        break;
                    }
                    max_row_id = max(max_row_id, pos[ch][i].x);
                    min_row_id = min(min_row_id, pos[ch][i].x);
                }
                if (ok) {
                    while (last_unused_ch <= ch) {
                        res.push_back({min_row_id, col_id});
                        res.push_back({max_row_id, col_id});
                        last_unused_ch++;
                    }
                } else {
                    cout << "NO\n";
                    return;
                }
            }
        } 
    }

    assert(res.size() <= 52);

    int cur_ch = 0;
    for (int i = 0; i < res.size(); i += 2) {
        if (res[i].x == res[i + 1].x) {
            for (int j = res[i].y; j <= res[i + 1].y; j++) {
                empty_grid[res[i].x][j] = char(cur_ch + 'a');
            }
        } else {
            for (int j = res[i].x; j <= res[i + 1].x; j++) {
                empty_grid[j][res[i].y] = char(cur_ch + 'a');
            }
        }
        cur_ch++;
    }

    bool same = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != empty_grid[i][j]) {
                same = false;
            }
        }
    }
    if (same) {
        cout << "YES\n";
        cout << res.size() / 2 << "\n";
        for (int i = 0; i < res.size(); i += 2) {
            cout << res[i].x + 1 << " " << res[i].y + 1 << " " << res[i + 1].x + 1 << " " << res[i + 1].y + 1 << "\n";
        }
    } else {
        cout << "NO\n";
    }
}
